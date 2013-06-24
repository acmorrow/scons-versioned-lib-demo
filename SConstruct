#EnsureSConsVersion(2, 3, 0)

AddOption('--prefix',
          dest='prefix',
          type='string',
          nargs=1,
          action='store',
          metavar='DIR',
          help='installation prefix')

env = Environment(
    tools=["default", "packaging"],
    PREFIX=GetOption('prefix'))

def AddPackageTag(env, package_tag, target):
    env.Tag(target, PACKAGE=package_tag)
env.AddMethod(AddPackageTag)

def TaggedPackage(env, tag, **kwargs):
    files = env.FindInstalledFiles()
    # NOTE 2: You will see from this print that the dev-link gets printed as broken
    # characters. I think when you extend _INSTALLED_FILES you need to enclose in
    # brackets. However, even when you do that, you don't get consistent names with the other
    # files, which all contain the complete install prefix, but the dev-link gets a relative
    # prefix.
    for f in files:
        f_tags = hasattr(f, "PACKAGING_PACKAGE") and getattr(f, "PACKAGING_PACKAGE") or []
        print(str(f), f_tags)
    tagged = [f for f in files if hasattr(f, "PACKAGING_PACKAGE") and getattr(f, "PACKAGING_PACKAGE") == tag]
    return env.Package(source=tagged, NAME=tag, **kwargs)
env.AddMethod(TaggedPackage)

env.SConscript('src/SConscript', variant_dir='build', exports=['env'])
