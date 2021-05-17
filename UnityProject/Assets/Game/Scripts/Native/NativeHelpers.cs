using UnityEngine;

namespace Native
{
    public static class UnityTypeHelpers
    {
        public static T Downcast<T>(Object obj) where T : class { return obj as T; }
    }
}
