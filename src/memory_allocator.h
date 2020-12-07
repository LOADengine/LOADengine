/*
 * File: memory_allocator.h
 * Author: Daniel Gaard Hansen
 * Date: 07_12_2020 09:30
 * Description: Contains basic memory allocator.
 */
#pragma once

// System
#include <stdio.h>

// Project
#include "common_types.h"

//
// Basic linear memory
//
struct Linear_Memory
{
	u8* memory_base;
	i32 total_bytes;
	i32 used_bytes;
};


//
// Creates a Linear Memory struct, allocates using new
//
Linear_Memory linear_memory_create(i32 totalBytes)
{
	Linear_Memory alloc = {};

	alloc.total_bytes = totalBytes;

	// @Incomplete Maybe use VirtualAlloc or something per platform?  
	alloc.memory_base = new u8[totalBytes];

	for(int i = 0; i < alloc.total_bytes; i++)
	{
		alloc.memory_base[i] = 0;
	}
	
	return alloc;
}

//
// Pushes #numBytes bytes to the memory allocator. Returns null if there's no room. 
//
void *push_memory(Linear_Memory *alloc, i32 numBytes)
{
	//
	// Check if there is space for allocation
	//
	i32 remaining_alloc_memory = alloc->total_bytes - alloc->used_bytes;

	if(remaining_alloc_memory < numBytes)
	{
		printf("ERROR: Alloc does not have space for %d byte bytes! %d bytes remaining",
			   numBytes, remaining_alloc_memory);
		return nullptr;
	}

	//
	// We got enough memory!
	//
	u8 *result = alloc->memory_base + alloc->used_bytes;
	alloc->used_bytes += numBytes;

	return result;
   
}

void print_memory_state(Linear_Memory *alloc)
{
	printf("Printing memory layout of allocator starting at address %p\n",
		   alloc->memory_base);
	for(int i = 0; i < alloc->total_bytes; i++)
	{
		printf("[%d] %c\n", i, (i8)alloc->memory_base[i]); 
	}
}
