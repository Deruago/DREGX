/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#include "dregx/CompilerGenerator.h"

#include "Deamer/File/Generate/Compiler.h"

int main(int argc, char* argv[])
{
		// Generate: dregx
	::dregx::CompilerGenerator dregx_compiler;
	::deamer::file::generate::Compiler dregx_WriteToDisk(dregx_compiler.Generate());
	dregx_WriteToDisk.SetProjectType(::deamer::file::generate::Compiler::ProjectType::single);
	dregx_WriteToDisk.Generate();


	return 0;
}
