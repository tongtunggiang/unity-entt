using System;
using System.Collections.Generic;
using System.Linq;

namespace BindingsGenerator
{
    /// <summary>
    /// Standalone binding generator with ECS bindings generating ability.
    /// Built on top of Jackson Dunstan's Unity Editor generator
    /// </summary>
    /// <author>
    /// Giang Tong, 2020, https://tongtunggiang.com
    /// </author>
    class Program
    {
        const string DEFAULT_ARG = "--default";
        const string UNITY_PATH_ARG = "--unityDllPath=";
        const string ECS_ARG = "--ecs";
        const string IN_VS_TEST = "--pressToContinue";

        static void Main(string[] args)
        {
            // Default mode requires Unity path being passed
            if (args.Contains(DEFAULT_ARG))
            {
                int idx = Array.FindIndex(args, s => s.Contains(UNITY_PATH_ARG));
                if (idx < 0)
                {
                    Debug.LogErrorFormat("Missing Unity path. Pass it with option {0}", UNITY_PATH_ARG + "/path/to/Unity/");
                    return;
                }

                string unityPath = args[idx];
                unityPath = unityPath.Substring(UNITY_PATH_ARG.Length);
                DefaultBindings.UnityDllsDirPath = unityPath;
                DefaultBindings.Generate();
            }

            if (args.Contains(ECS_ARG))
            {
                ECSBindings.Generate();
            }
        }
    }
}
