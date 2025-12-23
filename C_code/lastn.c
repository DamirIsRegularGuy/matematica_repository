#include "WolframLibrary.h"

DLLEXPORT int lastn(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
    MTensor lst = MArgument_getMTensor(Args[0]);
    mint n = MArgument_getInteger(Args[1]);

    mint len = libData->MTensor_getDimensions(lst)[0];
    mint start = len - n + 1;

    if (start < 1) start = 1;

    MTensor out;
    mint dims[1];
    dims[0] = len - start + 1;

    libData->MTensor_new(MType_Integer, 1, dims, &out);

    mint *lstData = libData->MTensor_getIntegerData(lst);
    mint *outData = libData->MTensor_getIntegerData(out);

    for (mint i = 0; i < dims[0]; i++) {
        outData[i] = lstData[start - 1 + i];
    }

    MArgument_setMTensor(Res, out);
    return LIBRARY_NO_ERROR;
}
