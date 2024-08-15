#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef CV_PLATFORM_WINDOWS
	extern Calavera::Application* Calavera::CreateApplication();

	int main(int argc, char** argv)
	{
		Calavera::Log::Init();

		CV_PROFILE_BEGIN_SESSION("Startup", "CalaveraProfile-Startup.json");
		auto app = Calavera::CreateApplication();
		CV_PROFILE_END_SESSION();

		CV_PROFILE_BEGIN_SESSION("Runtime", "CalaveraProfile-Runtime.json");
		app->Run();
		CV_PROFILE_END_SESSION();

		CV_PROFILE_BEGIN_SESSION("Shutdown", "CalaveraProfile-Shutdown.json");
		delete app;
		CV_PROFILE_END_SESSION();
	}

#endif // CV_PLATFORM_WINDOWS

#endif // !ENTRYPOINT_H
