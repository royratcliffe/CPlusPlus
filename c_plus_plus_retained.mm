// CPlusPlus c_plus_plus_retained.mm
//
// Copyright © 2010, Roy Ratcliffe, Pioneering Software, United Kingdom
// All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
// EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
//------------------------------------------------------------------------------

#import "c_plus_plus_retained.h"
#import "CPlusPlusRetainer.h"

void c_plus_plus_retained::retain()
{
	if (retainer_object)
	{
		[(CPlusPlusRetainer *)retainer_object retain];
	}
	else
	{
		retainer_object = [[CPlusPlusRetainer alloc] initWithRetained:this];
		// Hereafter you must never delete this object. Doing so will break the implicit design contract. Asking to retain actually places the retained object within the scope of retain-release memory management. Only releasing hereafter will release the retainer and delete the object. Henceforward, delete becomes release. Calling delete will double-delete this object.
	}
}

void c_plus_plus_retained::release()
{
	if (retainer_object)
	{
		[(CPlusPlusRetainer *)retainer_object release];
	}
}

void c_plus_plus_retained::autorelease()
{
	if (retainer_object)
	{
		[(CPlusPlusRetainer *)retainer_object autorelease];
	}
}
