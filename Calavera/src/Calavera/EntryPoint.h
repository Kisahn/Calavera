#pragma once

#ifdef CV_PLATFORM_WINDOWS

extern Calavera::Application* Calavera::CreateApplication();

int main(int argc, char** argv)
{
	Calavera::Log::Init();
	CV_CORE_WARN("Initialized Log !");
	int a = 5;
	CV_INFO("Hello ! Var={0}", a);

	auto app = Calavera::CreateApplication();
	app->Run();
	delete app;
}

#endif