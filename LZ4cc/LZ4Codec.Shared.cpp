/*
Copyright (c) 2013, Milosz Krajewski
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided 
that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions 
  and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions 
  and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN 
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "stdafx.h"

#include "LZ4Codec.h"

namespace NAMESPACE {

void LZ4Codec::CheckArguments(
	array<Byte>^ input, int inputOffset, int% inputLength)
{
	if (inputLength < 0) inputLength = input->Length - inputOffset;

	if (input == nullptr) throw gcnew ArgumentNullException("input");
	if (inputOffset < 0 || inputOffset + inputLength > input->Length)
		throw gcnew ArgumentException("inputOffset and inputLength are invalid for given input");
}

void LZ4Codec::CheckArguments(
	array<Byte>^ input, int inputOffset, int% inputLength,
	array<Byte>^ output, int outputOffset, int% outputLength)
{
	if (inputLength < 0) inputLength = input->Length - inputOffset;
	if (inputLength == 0)
	{
		outputLength = 0;
		return;
	}

	if (input == nullptr) throw gcnew ArgumentNullException("input");
	if (inputOffset < 0 || inputOffset + inputLength > input->Length)
		throw gcnew ArgumentException("inputOffset and inputLength are invalid for given input");

	if (outputLength < 0) outputLength = output->Length - outputOffset;
	if (output == nullptr) throw gcnew ArgumentNullException("output");
	if (outputOffset < 0 || outputOffset + outputLength > output->Length)
		throw gcnew ArgumentException("outputOffset and outputLength are invalid for given output");
}

}