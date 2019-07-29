Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the File-Writing Tutorial!
Prerequesites: Strings

This tutorial shows you how to create and write to files.
Before you begin looking at this tutorial, there
is one important thing that should be known, that
can confuse a lot of beginners:

This line:
file << "TEST WRITE TO FILE." << std::endl;

does not actually write to the file, it writes to a temporary
string that is stored in RAM. Every time you use "file << ...",
you append to the string that is in RAM, and nothing is written
to the file. Eventually, when you close the file, "ofs.close();",
it will write the huge string to the file, and then close.

However, in this tutorial, "ofs.close();" does not appear, and
yet it still works. Remember how we explained Stack and Heap?
when you make an "ofstream file", you are creating that file on the
stack of "int main()". When "int main()" ends, the stack is erased.
While the stack is being erased, it calls the destructor of "ofstream file",
and in that destructor, it writes to the file, and then closes.

This is important to know because sometimes people forget, and it can 
cause a lot of problems in the future if you are not careful
