using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BindingsGenerator
{

    static class CommonPath
    {
        public const string UnityProjectName = "UnityProject";
        public const string NativeScriptName = "NativeScript";

        public static class Unity
        {
            public static readonly string ProjectDirPath = Path.Combine(
               Directory.GetCurrentDirectory(),
               Path.Combine("..",
                   Path.Combine("..",
                       UnityProjectName)));
            public static readonly string ProjectDllDirPath = Path.Combine(
                ProjectDirPath,
                Path.Combine(
                    "Library",
                    "ScriptAssemblies"));
            public static readonly string AssetsDirPath = Path.Combine(
                ProjectDirPath,
                "Assets");
        }

        public static class Native
        {
            public static readonly string BindingsSourcesDirPath = Path.Combine(
               Directory.GetCurrentDirectory(),
               Path.Combine("..",
                   Path.Combine("..",
                       Path.Combine(NativeScriptName, 
                           Path.Combine("Source", "Bindings")))));

            public static readonly string ECSComponentSourcesDirPath = Path.Combine(
               Directory.GetCurrentDirectory(),
               Path.Combine("..",
                   Path.Combine("..",
                       Path.Combine(NativeScriptName,
                           Path.Combine("Source", 
                               Path.Combine("Simulation", "Components"))))));
        }

        public static readonly string DotNetDllsDirPath = new FileInfo(
                 new Uri(typeof(string).Assembly.CodeBase).LocalPath
             ).DirectoryName;
    }
}
