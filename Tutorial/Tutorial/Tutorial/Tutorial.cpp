// Tutorial.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>

#ifdef __cplusplus
extern "C"
{
#endif
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#ifdef __cplusplus
}
#endif

char* urlprotocolInfo()
{
	char *pInfo = (char*)malloc(40000);
	memset(pInfo, 0, 40000);

	av_register_all();

	struct URLProtocol *pUp = nullptr;

	//input
	struct URLProtocol **pp = &pUp;
	avio_enum_protocols((void**)pp, 0);
	while ((*pp) != nullptr)
	{
		sprintf_s(pInfo, 40000, "%s[In ][%10s]\n", pInfo, avio_enum_protocols((void**)pp, 0));
	}

	//output
	pUp = nullptr;
	pp = &pUp;
	avio_enum_protocols((void**)pp, 1);
	while ((*pp) != nullptr)
	{
		sprintf_s(pInfo, 40000, "%s[Out ][%10s]\n", pInfo, avio_enum_protocols((void**)pp, 1));
	}

	return pInfo;
}

char* configurationInfo()
{
	char* pInfo = (char*)malloc(40000);
	memset(pInfo, 0, 40000);
	av_register_all();

	sprintf_s(pInfo, 40000, "%s\n", avcodec_configuration());

	return pInfo;
}

int main()
{
	std::cout << "-------------------protocol---------------------------" << std::endl;
	char *pProtocolInfo = urlprotocolInfo();
	std::cout << pProtocolInfo << std::endl;
	free(pProtocolInfo);

	std::cout << "-------------------build configuration---------------------------" << std::endl;
	char *pConfiguration = configurationInfo();
	std::cout << pConfiguration << std::endl;
	free(pConfiguration);

	system("pause");
    return 0;
}

