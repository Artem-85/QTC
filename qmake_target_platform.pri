win32 {

    CONFIG += PLATFORM_WIN
    DEFINES += PLATFORM_WIN

    platform_path = win

#    !build_pass:message(PLATFORM_WIN)

    win32-g++ {
        CONFIG += COMPILER_GCC

        compiler_path = gcc

#        !build_pass:message(COMPILER_GCC)
    }
    win32-msvc2017 {

        CONFIG += COMPILER_MSVC2017

        compiler_path = msvc17

#        !build_pass:message(COMPILER_MSVC2017)

        win32-msvc2017:QMAKE_TARGET.arch = x86_64
    }

}

linux {

    CONFIG += PLATFORM_LINUX
    DEFINES += PLATFORM_LINUX

    platform_path = linux

#    !build_pass:message(PLATFORM_LINUX)

    # Make QMAKE_TARGET arch available for Linux
#    !contains(QT_ARCH, x86_64) {
#        QMAKE_TARGET.arch = x86
#    } else {
#        QMAKE_TARGET.arch = x86_64
#    }
    linux-g++ {
        CONFIG += COMPILER_GCC

        compiler_path = gcc

#        message(COMPILER_GCC)
    }

} 
#contains(QMAKE_TARGET.arch, x86_64) {

contains(QT_ARCH, x86_64) {

    CONFIG += PROCESSOR_x64

    processor_path = x64

#    !build_pass:message(PROCESSOR_x64)

} else {

    CONFIG += PROCESSOR_x86

    processor_path = x86

#    !build_pass:message(PROCESSOR_x86)

}

CONFIG(debug, release|debug) {

    CONFIG += BUILD_DEBUG
    DEFINES += BUILD_DEBUG

    config_path = debug

#    !build_pass:message(BUILD_DEBUG)


} else {

    CONFIG += BUILD_RELEASE
    DEFINES += BUILD_RELEASE

    config_path = release

#    !build_pass:message(BUILD_RELEASE)

}

destination_path = $${platform_path}_$${processor_path}/$${compiler_path}/$${config_path}
