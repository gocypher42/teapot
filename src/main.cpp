#include <fmt/core.h>

class App
{
public:
  static int Run(int argc, char **argv);

private:
};

int App::Run(int /*argc*/, char ** /*argv*/)
{
  fmt::print("Hello {}!\n", "World");

  return 0;
};

int main(int argc, char *argv[])
{
  App app;
  return app.Run(argc, argv);
}
