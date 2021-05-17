using UnityEngine;
using UnityEditor;
using System.Diagnostics;
using System.IO;
using System;
using System.ComponentModel;

using Debug = UnityEngine.Debug;

namespace NativeScript.Editor
{
    /// <summary>
    /// Menus for the Unity Editor
    /// </summary>
    /// 
    /// <author>
    /// Jackson Dunstan, 2018, http://JacksonDunstan.com
    /// </author>
    /// 
    /// <license>
    /// MIT
    /// </license>
    public static class EditorMenus
    {

        static readonly string UNITY_DLL_PATH = new FileInfo(
             new Uri(typeof(GameObject).Assembly.CodeBase).LocalPath
         ).DirectoryName;

        static readonly string GENERATOR_TOOL_EXE = "BindingsGenerator.exe";
        static readonly string GENERATOR_TOOL_DIR = Application.dataPath + "/../../Tools/BindingsGenerator";
        static readonly string GENERATOR_TOOL_PATH = GENERATOR_TOOL_DIR + "/" + GENERATOR_TOOL_EXE;

        [MenuItem("NativeScript/Generate Bindings #%g")]
        public static void Generate()
        {
            try
            {
                Process process = new Process();
                process.StartInfo.FileName = GENERATOR_TOOL_PATH;
                process.StartInfo.CreateNoWindow = true;
                process.StartInfo.UseShellExecute = false;
                process.StartInfo.Arguments = string.Format("--default --unityDllPath={0} --noShell", UNITY_DLL_PATH);
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardError = true;
                process.StartInfo.WorkingDirectory = GENERATOR_TOOL_DIR;
                process.OutputDataReceived += new DataReceivedEventHandler(OutputHandler);
                process.ErrorDataReceived += new DataReceivedEventHandler(ErrorHandler);

                Debug.LogFormat("{0} {1}", GENERATOR_TOOL_EXE, process.StartInfo.Arguments);

                process.Start();

                process.BeginOutputReadLine();
                process.BeginErrorReadLine();

                process.WaitForExit();
            }
            catch (Win32Exception ex)
            {
                Debug.LogErrorFormat("Cannot find file {0}", GENERATOR_TOOL_PATH);
            }
        }

        static void OutputHandler(object sendingProcess, DataReceivedEventArgs outLine)
        {
            if (!string.IsNullOrEmpty(outLine.Data))
                Debug.Log(outLine.Data);
        }

        static void ErrorHandler(object sendingProcess, DataReceivedEventArgs outLine)
        {
            if (!string.IsNullOrEmpty(outLine.Data))
                Debug.LogError(outLine.Data);
        }

        [MenuItem("NativeScript/Reload Plugin #%r")]
        public static void Reload()
        {
            Bindings.Reload();
        }
    }
}
