///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	OPCODE - Optimized Collision Detection
 *	Copyright (C) 2001 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Opcode.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Main file for Opcode.dll.
 *	\file		Opcode.h
 *	\author		Pierre Terdiman
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __OPCODE_H__
#define __OPCODE_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Things to help us compile on non-windows platforms

#if defined(__APPLE__) || defined(__MACOSX__)
#if __APPLE_CC__ < 1495
#define sqrtf sqrt
#define sinf sin
#define cosf cos
#define acosf acos
#define asinf sinf
#endif
#endif

#ifndef _MSC_VER

#ifndef __int64
#define __int64 long long int
#endif
#define __stdcall /* */

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Compilation messages
#ifdef _MSC_VER
	#if defined(OPCODE_EXPORTS)
		// #pragma message("Compiling OPCODE")
	#elif !defined(OPCODE_EXPORTS)
		// #pragma message("Using OPCODE")
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Automatic linking
		#ifndef BAN_OPCODE_AUTOLINK
			#ifdef _DEBUG
				//#pragma comment(lib, "Opcode_D.lib")
			#else
				//#pragma comment(lib, "Opcode.lib")
			#endif
		#endif
	#endif
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Preprocessor
#ifndef ICE_NO_DLL
	#ifdef OPCODE_EXPORTS
		#define OPCODE_API// __declspec(dllexport)
	#else
		#define OPCODE_API// __declspec(dllimport)
	#endif
#else
		#define OPCODE_API
#endif

	#include "ode/OPC_IceHook.h"

	namespace Opcode
	{
		// Bulk-of-the-work
		#include "ode/OPC_Settings.h"
		#include "ode/OPC_Common.h"
		#include "ode/OPC_MeshInterface.h"
		// Builders
		#include "ode/OPC_TreeBuilders.h"
		// Trees
		#include "ode/OPC_AABBTree.h"
		#include "ode/OPC_OptimizedTree.h"
		// Models
		#include "ode/OPC_BaseModel.h"
		#include "ode/OPC_Model.h"
		#include "ode/OPC_HybridModel.h"
		// Colliders
		#include "ode/OPC_Collider.h"
		#include "ode/OPC_VolumeCollider.h"
		#include "ode/OPC_TreeCollider.h"
		#include "ode/OPC_RayCollider.h"
		#include "ode/OPC_SphereCollider.h"
		#include "ode/OPC_OBBCollider.h"
		#include "ode/OPC_AABBCollider.h"
		#include "ode/OPC_LSSCollider.h"
		#include "ode/OPC_PlanesCollider.h"
		// Usages
		#include "ode/OPC_Picking.h"
		// Sweep-and-prune
		#include "ode/OPC_BoxPruning.h"
		#include "ode/OPC_SweepAndPrune.h"

		FUNCTION OPCODE_API bool InitOpcode();
		FUNCTION OPCODE_API bool CloseOpcode();
	}

#endif // __OPCODE_H__