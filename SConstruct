#EnsureSConsVersion(2, 3, 0)

AddOption('--prefix',
          dest='prefix',
          type='string',
          nargs=1,
          action='store',
          metavar='DIR',
          help='installation prefix')

env = Environment(
    tools = ["default", "packaging"],
    PREFIX = GetOption('prefix'))

env.SConscript('src/SConscript', variant_dir='build', exports=['env'])
