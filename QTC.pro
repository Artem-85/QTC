TEMPLATE = subdirs

#VERSION = 0.0.0.1
#APPNAME = QTC
#ORGNAME = arplyu
#ORGDOMAIN = www.zzz.xy

#linux {
#    DEFINES += APPLICATION_VERSION=\\\"$$VERSION\\\" \
#    APPLICATION_NAME=\\\"$$APPNAME\\\" \
#    ORGANIZATION_NAME=\\\"$$ORGNAME\\\" \
#    ORGANIZATION_DOMAIN=\\\"$$ORGDOMAIN\\\"

#    platform_path = linux

#    }

#win32 {
#    DEFINES += APPLICATION_VERSION=\"$$VERSION\" \
#    APPLICATION_NAME=\"$$APPNAME\" \
#    ORGANIZATION_NAME=\"$$ORGNAME\" \
#    ORGANIZATION_DOMAIN=\"$$ORGDOMAIN\"

#    platform_path = win

#    }

SUBDIRS += \
    sources/QTC_Main.pro \
    sources/Core/QTC_Core.pro
