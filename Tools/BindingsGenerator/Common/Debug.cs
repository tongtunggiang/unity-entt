using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BindingsGenerator
{
    public static class Debug
    {
        public static void LogFormat(string format, params object[] args)
        {
            _Log(ConsoleColor.White, format, args);
        }

        public static void LogWarningFormat(string format, params object[] args)
        {
            _Log(ConsoleColor.Yellow, format, args);
        }

        public static void Log(string s)
        {
            LogFormat(s);
        }

        public static void LogWarning(string s)
        {
            LogWarningFormat(s);
        }

        private static void _Log(ConsoleColor foreground, string format, params object[] args)
        {
            Console.ForegroundColor = foreground;
            Console.WriteLine(format, args);
            Console.ForegroundColor = ConsoleColor.White;
        }

        public static void LogErrorFormat(string format, params object[] args)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Error.WriteLine(format, args);
            Console.ForegroundColor = ConsoleColor.White;
        }

        public static void LogError(string s)
        {
            LogErrorFormat(s);
        }
    }
}
