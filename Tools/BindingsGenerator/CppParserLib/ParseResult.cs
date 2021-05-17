using System;
using System.Collections.Generic;
using System.Text;

namespace CppParser
{
    public class ParseResult
    {
        public string fileName;
        public string fullFilePath;
        public string rawText;
        public List<CppMacro> macros = new List<CppMacro>();
        public List<CppStruct> structs = new List<CppStruct>();
    }

    public class CppMemberVariable
    {
        public string type;
        public string name;
    }

    public class CppStruct
    {
        public string name;
        //public List<CppMemberVariable> members;
        public List<string> members = new List<string>();
    }

    public class CppMacro
    {
        public string name;
        public string value;
    }
}
