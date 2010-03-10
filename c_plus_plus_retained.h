// CPlusPlus c_plus_plus_retained.h
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

// Defines the public interface. Any general C++ translation unit sees this interface declaration. It contains nothing about Objective-C or Objective-C++. Such dependencies appear at link- and run-time, not at compile-time. This is by design. You can include this header in any C++ source.
//
// Semantically, the c_plus_plus_retained class is no retain count. It remains initially invisible respecting retain-release memory management. This changes when you retain it for the first time. At that point, you no longer delete the object. You must release it, doing so manually or by auto-releasing.
//
// Note, the struct cannot belong to a name space. Structs are classes. The difference is only one: the initial visibility; public for struct, private for class.
struct c_plus_plus_retained
{
	c_plus_plus_retained() : retainer_object(0) {}
	virtual ~c_plus_plus_retained() {}
	void retain();
	void release();
	// Releasing has no effect until you retain it.
	void autorelease();
	
private:
	// Why void pointer? Why not CPlusPlusRetainer pointer? The design aims to clearly separate C++ from Objective-C++. The two halves of this equation should never meet except within the implementation, never within the interface. Simple reason, the header becomes included by standard C++ translation units. Includers do not want to convert C++ sources to Objective-C++ sources, cpp to mm. That would be an unnecessary burden. Nor would developers want to deal with compiling as Objective-C++ despite the standard extension. Too messy. Better to keep the implementation separate. Hence, only the linking phase has Objective-C++ dependency. Compiling remains agnostic.
	void *retainer_object;
};