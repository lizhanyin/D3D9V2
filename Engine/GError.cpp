#include "GError.h"

namespace AhlinI {

	GError::GError(int code, const char* msg)
	{
		this->code = code;
		this->msg = msg;
	}

	const char* GError::GetMsg()
	{
		return msg;
	}

}