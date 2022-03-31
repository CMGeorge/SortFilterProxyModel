CONFIG += c++11
QT += qml quick core
!wasm-emscripten{
    QT += sql
}
include (SortFilterProxyModel.pri)

#TARGET = $$qtLibraryName(SortFilterProxyModel)
URI = SortFilterProxyModel
QMAKE_MOC_OPTIONS += -Muri=$$URI

TARGETPATH = SortFilterProxyModel

HEADERS += \
    SortFilterProxyModelPlugin.h


#include($$PWD/../constants.pri)
#PRO_RELATIVE_PATH = relative_path($$PWD, $$PROJECT_BASE)
#error (PROJECT_OUT_PWD = $$PRO_RELATIVE_PATH = $$PROJECT_BASE)
TEMPLATE = lib
CONFIG += plugin c++11


equals(TEMPLATE, app): TEMPLATE = aux

isEmpty(TARGETPATH): error("Must set TARGETPATH (QML import name)")

!isEmpty(DYNAMIC_QMLDIR) {
    qmldir_path = $$OUT_PWD
    write_file($${qmldir_path}/qmldir, DYNAMIC_QMLDIR)|error("Aborting.")
} else {
    qmldir_path = $$_PRO_FILE_PWD_
}

qmldir_file = $${qmldir_path}/qmldir

fq_qml_files =
for(qmlf, QML_FILES): fq_qml_files += $$absolute_path($$qmlf, $$_PRO_FILE_PWD_)

fq_aux_qml_files =
for(qmlf, AUX_QML_FILES): fq_aux_qml_files += $$absolute_path($$qmlf, $$_PRO_FILE_PWD_)

load(qt_build_paths)

#defined($$CUSTOM_OUT_PATH,var):
defined(CUSTOM_OUT_PATH,var):!isEmpty(CUSTOM_OUT_PATH): MODULE_BASE_OUTDIR = $$CUSTOM_OUT_PATH
else:MODULE_BASE_OUTDIR = $$OUT_PWD/../../

DESTDIR = $$MODULE_BASE_OUTDIR/qml/$$TARGETPATH

static: \
    CONFIG += builtin_resources
else: \
    CONFIG += install_qml_files

builtin_resources {
    URITARGET = $$replace(URI, "\\.", "_")
    # In static builds, the QML engine reads also the qmldir file from the resources.
    static: $${URITARGET}.files = $$qmldir_file
    # Ensure the QML files are included in the resources.
    $${URITARGET}.files += $$fq_qml_files
    # qt-project.org/imports is the path used for locating imports inside the resources
    $${URITARGET}.prefix = /qt-project.org/imports/$$TARGETPATH
    RESOURCES += $${URITARGET}
}

# Install rules
qmldir.base = $$qmldir_path
# Tools need qmldir and plugins.qmltypes always installed on the file system

qmldir.files = $$qmldir_file
install_qml_files: qmldir.files += $$fq_qml_files
qmldir.path = $$MODULE_BASE_OUTDIR/qml/$$TARGETPATH
INSTALLS += qmldir

qmlfiles.base = $$_PRO_FILE_PWD_
qmlfiles.files = $$fq_aux_qml_files
install_qml_files: qmlfiles.files += $$fq_qml_files
qmlfiles.path = $${qmldir.path}
INSTALLS += qmlfiles

!debug_and_release|!build_all|CONFIG(release, debug|release) {
    !prefix_build {
        COPIES += qmldir
    } else {
        # For non-installed static builds, tools need qmldir and plugins.qmltypes
        # files in the build dir
        qmldir2build.files = $$qmldir_file $$fq_aux_qml_files
        qmldir2build.path = $$DESTDIR
        COPIES += qmldir2build
    }
}
CONFIG+=install install_ok


#include($$PWD/../qml_pro.pri)

#load(qml_module)
