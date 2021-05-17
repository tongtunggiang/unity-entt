using CppParser;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BindingsGenerator.ECS
{
    static class ECSParseResultUtilities
    {
        public static bool IsTagFile(string fileContent)
        {
            return fileContent.Contains("/* TAG_COMPONENT */");
        }
        public static bool IsSettingsFile(string fileContent)
        {
            return fileContent.Contains("/* GAME_SETTINGS_COMPONENT */");
        }
        public static bool IsStateFile(string fileContent)
        {
            return fileContent.Contains("/* GAME_STATE_COMPONENT */");
        }

        public static bool IsComponentFile(string fileContent)
        {
            return !IsStateFile(fileContent) && !IsSettingsFile(fileContent) && !IsTagFile(fileContent);
        }
    }
}
