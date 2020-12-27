#include "../include/RegZlibModule.h"

#include <langX/langXSimple.h>

#include <string>
#include <string.h>

#ifdef WIN32
#include "../../../lib/zlib-1.2.11/zlib.h"
#else
#include <zlib.h>
#endif

namespace langX {


	Object * langX_Zlib_compress(X3rdFunction *func, const X3rdArgs &args) {

		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String * string = (String*)a;
			int len = string->size();
			uLongf destLen = (len * 1.1) + 12;
			Bytef *destData = (Bytef*) calloc(destLen, 1);
			const Bytef *dataOriginal = (const Bytef *)string->getValue();
			String *ret = nullptr;

			int zResult = compress(destData, &destLen, dataOriginal, len);
			if (zResult == Z_OK)
			{
				 // ok
				char * abc = (char *)destData;
				std::string s1(abc, destLen);

				ret = Allocator::allocateString(s1);
			}
			else {
				// error
				// TODO throw excepltions.

			}

			free(destData);
			return ret;
		}

		return nullptr;
	}

	Object * langX_Zlib_decompress(X3rdFunction *func, const X3rdArgs &args) {

		const int CHUNK_SIZE = 3 * 1024 * 1024;

		Object *a = args.args[0];
		if (a && a->getType() == ObjectType::STRING)
		{
			String *string = (String*) a;
			uint nLenSrc = string->size();

			z_stream strm;
			strm.zalloc = Z_NULL;
			strm.zfree = Z_NULL;
			strm.opaque = Z_NULL;
			strm.avail_in = 0;
			strm.next_in = Z_NULL;
			int ret = inflateInit(&strm);
			if (ret != Z_OK)
			{
				// something error.
				return nullptr;
			}

			char *in = (char*)calloc(1, nLenSrc);
			memcpy(in, string->getValue(), nLenSrc);

			strm.avail_in = nLenSrc;
			strm.next_in = (Bytef*)in;

			char out[CHUNK_SIZE] = { 0 };
			strm.avail_out = CHUNK_SIZE;
			strm.next_out = (Bytef*)out;

			ret = inflate(&strm, Z_NO_FLUSH);

			Object *objReturn = nullptr;
			if (ret == Z_OK || ret == Z_STREAM_END)
			{
				if (strm.avail_out > 0 || ret == Z_STREAM_END)
				{
					// 解压缩成功
					int strSize = CHUNK_SIZE - strm.avail_out;
					std::string t(out, strSize);
					objReturn = Allocator::allocateString(t);
				}
			}

			free(in);
			inflateEnd(&strm);

			return objReturn;
		}

		return nullptr;
	}


	Object * langX_Zlib_compressFile(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zlib_compressFile error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zlib_decompressFile(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Zlib_decompressFile error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}


	Object * langX_Zlib_cFile(X3rdFunction *func, const X3rdArgs &args) {

		return langX_Zlib_compressFile(func, args);
	}


	Object * langX_Zlib_deFile(X3rdFunction *func, const X3rdArgs &args) {

		return langX_Zlib_decompressFile(func, args);
	}


	int regZlib(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("Zlib");
		info->addFunction("compress", create3rdFunc("compress", langX_Zlib_compress));
		info->addFunction("decompress", create3rdFunc("decompress", langX_Zlib_decompress));
		info->addFunction("compressFile", create3rdFunc("compressFile", langX_Zlib_compressFile));
		info->addFunction("decompressFile", create3rdFunc("decompressFile", langX_Zlib_decompressFile));
		info->addFunction("cFile", create3rdFunc("cFile", langX_Zlib_cFile));
		info->addFunction("deFile", create3rdFunc("deFile", langX_Zlib_deFile));

		space->putClass(info);

		return 0;
	}
}
