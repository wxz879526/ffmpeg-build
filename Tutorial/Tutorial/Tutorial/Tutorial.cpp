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
#include "libavfilter/avfilter.h"
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

char* avfilterInfor()
{
	char* pInfo = (char*)malloc(40000);
	memset(pInfo, 0, 40000);
	avfilter_register_all();

	auto f_temp = avfilter_next(nullptr);
	while (f_temp != nullptr)
	{
		sprintf_s(pInfo, 40000, "%s[%15s]\n", pInfo, f_temp->name);
		f_temp = f_temp->next;
	}

	return pInfo;
}

char* avcodecinfo()
{
	char *pInfo = (char*)malloc(40000);
	memset(pInfo, 0, 40000);

	av_register_all();

	AVCodec *c_temp = av_codec_next(nullptr);
	while (c_temp != nullptr)
	{
		if (c_temp->decode != nullptr)
		{
			sprintf_s(pInfo, 40000, "%s[Dec]", pInfo);
		}
		else
		{
			sprintf_s(pInfo, 40000, "%s[Enc]", pInfo);
		}

		switch (c_temp->type)
		{
		case AVMEDIA_TYPE_AUDIO:
			sprintf_s(pInfo, 40000, "%s[Audio]", pInfo);
			break;
		case AVMEDIA_TYPE_VIDEO:
			sprintf_s(pInfo, 40000, "%s[Video]", pInfo);
			break;
		default:
			sprintf_s(pInfo, 40000, "%s[Other]", pInfo);
			break;
		}

		sprintf_s(pInfo, 40000, "%s %10s\n", pInfo, c_temp->name);

		c_temp = c_temp->next;
	}

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

	std::cout << "-------------------avfilter infor---------------------------" << std::endl;
	char *pAvfilterInfor = avfilterInfor();
	std::cout << pAvfilterInfor << std::endl;
	free(pAvfilterInfor);

	std::cout << "-------------------avcodec infor---------------------------" << std::endl;
	char *pAvCodec = avcodecinfo();
	std::cout << pAvCodec << std::endl;
	free(pAvCodec);

	system("pause");
    return 0;
}

