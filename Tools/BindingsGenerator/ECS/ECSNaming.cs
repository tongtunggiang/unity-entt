using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BindingsGenerator.ECS
{
    public static class ECSNaming
    {
        private static bool HasPrefix(string name, char prefix)
        {
            if (string.IsNullOrEmpty(name))
            {
                Debug.LogError("Null or empty name");
                return false;
            }

            if (name.Length < 2)
            {
                Debug.LogErrorFormat("Illegal name ({0}), must be more than 2 character");
                return false;
            }

            return (name[0] == prefix && char.IsUpper(name[1]));                
        }

        public static bool IsProperComponentName(string name)
        {
            return HasPrefix(name, 'C');
        }

        public static bool IsProperSystemName(string name)
        {
            return HasPrefix(name, 'S');
        }
    }
}
