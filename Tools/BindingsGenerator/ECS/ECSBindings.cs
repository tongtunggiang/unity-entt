using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CppParser;
using BindingsGenerator.ECS;

namespace BindingsGenerator
{
    static class ECSBindings
    {
        static readonly string CsharpPath = Path.Combine(
            CommonPath.Unity.AssetsDirPath,
            Path.Combine(
                "NativeScript",
                "ECSBindings.cs"));
        static readonly string CppSourcePath = Path.Combine(
            CommonPath.Native.BindingsSourcesDirPath,
            "ECSBindings.cpp");


        public class CodeGenBuilders
        {
            public Cplusplus Cpp = new Cplusplus();
            public Cs Csharp = new Cs();

            public class Cplusplus
            {
                public StringBuilder HeaderFiles = new StringBuilder();
                public StringBuilder GetComponentFunctions = new StringBuilder();
                public StringBuilder GetStateFunctions = new StringBuilder();
            }

            public class Cs
            {
                public StringBuilder Structs = new StringBuilder();
                public StringBuilder DelegateDeclaration = new StringBuilder();
                public StringBuilder DelegateAssignment = new StringBuilder();
            }
        }

        public static void Generate()
        {
            Debug.Log("Processing auto-gen ECS code");

            ParseResult[] parseResults = ParseFiles();
            CodeGenBuilders builders = new CodeGenBuilders();
            GenerateContent(parseResults, builders);
            InjectGeneratedContent(builders);

            Debug.Log("Finished auto-gen ECS code");
        }

        private static ParseResult[] ParseFiles()
        {
            var files = Directory.GetFiles(CommonPath.Native.ECSComponentSourcesDirPath);
            if (files.Length == 0)
            {
                Debug.LogWarningFormat("No component found in {0}", CommonPath.Native.ECSComponentSourcesDirPath);
                return null;
            }

            ParseResult[] parseResults = new ParseResult[files.Length];
            for (int i = 0; i < parseResults.Length; i++)
            {
                parseResults[i] = Parser.ParseFileName(files[i]);
            }

            return parseResults;
        }

        private static void GenerateContent(ParseResult[] parseResults, CodeGenBuilders builders)
        {
            foreach (var parseResult in parseResults)
            {
                if (ECSParseResultUtilities.IsSettingsFile(parseResult.rawText) ||
                    ECSParseResultUtilities.IsTagFile(parseResult.rawText))
                    continue;

                if (parseResult.structs.Count > 1)
                {
                    string error = string.Format("Error in file {0}: more than one struct contained, only one allowed.", parseResult.fileName);
                }

                if (!ECSNaming.IsProperComponentName(parseResult.structs[0].name))
                {
                    string error = string.Format("Illegal component name in file {0}: {1}, must follow the format CComponent.", parseResult.fileName, parseResult.structs[0].name);
                    throw new Exception(error);
                }

                GenerateCppContent(parseResult, builders);
                GenerateCsharpContent(parseResult, builders);
            }
        }


        private static string GenerateGetFunctionName(bool isState, string componentName)
        {
            string getFunctionFormat = "Get{0}";
            if (isState)
            {
                getFunctionFormat = "GetState{0}";
            }

            string componentNonPrefixName = componentName.Substring(1, componentName.Length - 1);
            return string.Format(getFunctionFormat, componentNonPrefixName);
        }


        private static void GenerateCppContent(ParseResult parseResult, CodeGenBuilders builders)
        {
            string include = string.Format("#include \"Components/{0}\"\n", parseResult.fileName);
            builders.Cpp.HeaderFiles.Append(include);

            // CPP: Generate functionName
            string componentTypeName = parseResult.structs[0].name;
            string getFunctionName = GenerateGetFunctionName(ECSParseResultUtilities.IsStateFile(parseResult.rawText), componentTypeName);

            // CPP: Get component/state 
            if (ECSParseResultUtilities.IsComponentFile(parseResult.rawText))
            {
                builders.Cpp.GetComponentFunctions.Append(string.Format("DEFINE_GET_COMPONENT({0}, {1})\n", componentTypeName, getFunctionName));
            }
            else if (ECSParseResultUtilities.IsStateFile(parseResult.rawText))
            {
                builders.Cpp.GetStateFunctions.Append(string.Format("DEFINE_GET_GAME_STATE({0}, {1})\n", componentTypeName, getFunctionName));
            }
        }


        private static void GenerateCsharpContent(ParseResult parseResult, CodeGenBuilders builders)
        {
            CppParser.CppStruct cppStruct = parseResult.structs[0];

            // CS: Generate struct
            string allMembers = "";
            foreach (var member in cppStruct.members)
            {
                if (String.IsNullOrEmpty(member))
                    throw new Exception(string.Format("Struct {0} has a blank member, perhaps an unsupported type when converting C++ to C#", cppStruct.name));
                allMembers += string.Format("\tpublic {0}\n", member);
            }

            string structFormat =
                "public struct {0}\n" +
                "{{\n" +
                "{1}" +
                "}}\n";
            builders.Csharp.Structs.Append(string.Format(structFormat, cppStruct.name, allMembers));

            // CS: Generate delegate state/components
            string delegateReturnType = cppStruct.name;
            string delegateParam = ECSParseResultUtilities.IsStateFile(parseResult.rawText) ?
                "" :
                "UInt32 entity";
            string getFunctionName = GenerateGetFunctionName(ECSParseResultUtilities.IsStateFile(parseResult.rawText), cppStruct.name);
            string delegateDelclaration = string.Format(
                "\t[UnmanagedFunctionPointer(CallingConvention.Cdecl)]\n" +
                "\tpublic delegate {0} {1}Type({2});\n" +
                "\tpublic static {1}Type {1};\n\n",
                delegateReturnType,
                getFunctionName,
                delegateParam);
            builders.Csharp.DelegateDeclaration.Append(delegateDelclaration);

            // CS: Generate getter state/components
            string delegateAssignment = string.Format(
                "\t\t{0} = Bindings.GetDelegate<{0}Type>(libraryHandle, \"{0}\");\n",
                getFunctionName
                );
            builders.Csharp.DelegateAssignment.Append(delegateAssignment);
        }

        private static void InjectGeneratedContent(CodeGenBuilders builders)
        {
            string cppContent = File.ReadAllText(CppSourcePath);

            cppContent = StringUtilities.InjectIntoString(
                cppContent,
                "/*BEGIN COMPONENT HEADER INCLUDE*/",
                "/*END COMPONENT HEADER INCLUDE*/",
                builders.Cpp.HeaderFiles.ToString());

            cppContent = StringUtilities.InjectIntoString(
                cppContent,
                "/*BEGIN GET COMPONENT FUNCTIONS*/",
                "/*END GET COMPONENT FUNCTIONS*/",
                builders.Cpp.GetComponentFunctions.ToString());

            cppContent = StringUtilities.InjectIntoString(
                cppContent,
                "/*BEGIN GET STATES FUNCTIONS*/",
                "/*END GET STATES FUNCTIONS*/",
                builders.Cpp.GetStateFunctions.ToString());


            string csContent = File.ReadAllText(CsharpPath);

            csContent = StringUtilities.InjectIntoString(
                csContent,
                "/*BEGIN TYPE DEFINITION*/",
                "/*END TYPE DEFINITION*/",
                builders.Csharp.Structs.ToString());


            builders.Csharp.DelegateAssignment.Append("\t\t");
            csContent = StringUtilities.InjectIntoString(
                csContent,
                "/*BEGIN DELEGATE ASSIGN*/",
                "/*END DELEGATE ASSIGN*/",
                builders.Csharp.DelegateAssignment.ToString());

            builders.Csharp.DelegateDeclaration.Append("\t");
            csContent = StringUtilities.InjectIntoString(
                csContent,
                "/*BEGIN DELEGATE DECLARATION*/",
                "/*END DELEGATE DECLARATION*/",
                builders.Csharp.DelegateDeclaration.ToString());

            // Update the content
            {
                string[] files = { CppSourcePath, CsharpPath };
                string[] contents = { cppContent, csContent };
                for (int i = 0; i < files.Length; i++)
                    File.WriteAllText(files[i], contents[i]);
            }
        }
    }
}
