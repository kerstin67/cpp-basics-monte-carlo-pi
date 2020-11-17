cxx.std = latest
using cxx

hxx{*}: extension = hpp
cxx{*}: extension = cpp

cxx.coptions =+ "-I$src_base"

exe{main}: {hxx cxx}{**}