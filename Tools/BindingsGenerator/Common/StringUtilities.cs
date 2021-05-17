using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BindingsGenerator
{
    public static class StringUtilities
    {
        public static string InjectIntoString(
           string contents,
           string beginMarker,
           string endMarker,
           string text)
        {
            for (int startIndex = 0; ;)
            {
                int beginIndex = contents.IndexOf(beginMarker, startIndex);
                if (beginIndex < 0)
                {
                    return contents;
                }
                int afterBeginIndex = beginIndex + beginMarker.Length;
                int endIndex = contents.IndexOf(endMarker, afterBeginIndex);
                if (endIndex < 0)
                {
                    throw new Exception(
                        string.Format(
                            "No end ({0}) for begin ({1}) at {2} after {3}",
                            endMarker,
                            beginMarker,
                            beginIndex,
                            startIndex));
                }
                string begin = contents.Substring(0, afterBeginIndex);
                string end = contents.Substring(endIndex);
                contents = begin + "\n" + text + end;
                startIndex = beginIndex + 1;
            }
        }
    }
}
