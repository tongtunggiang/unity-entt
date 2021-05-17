#pragma once

// C++ STL
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <map>
#include <set>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <random>
#include <algorithm>
#include <execution>
#include <cstdint>

// Unity generated bindings
#if UNITY_NATIVE_DLL
#include "Bindings.h"
#endif


#include "Profiler.h"

// Custom third party libs
#include "entt/entt.hpp"

#if USE_BULLET_MATH
#include "btBulletDynamicsCommon.h"
using Vector3 = btVector3;
#elif USE_EIGEN_MATH
#include "Eigen"
using Vector3 = Eigen::Vector3f;
#endif

// Custom type defines
using Registry = entt::registry;
using EventDispatcher = entt::dispatcher;
using Entity = entt::entity;

