#pragma once

#ifdef CV_PLATFORM_WINDOWS

extern Calavera::Application* Calavera::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Calavera::CreateApplication();
	app->Run();
	delete app;
}

#endif