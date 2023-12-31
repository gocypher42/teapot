#include "teapot.h"
#include "teapot_args_parser.h"

int main(int argc, char **argv)
{
  TeaPotArgsParser args_parser;
  if (!args_parser.ParseArgs(argc, argv)) { return -1; }

  TeaPot teapot(args_parser.GetArgs());

  return teapot.Run();
}
