DESCRIPTION = "MATHLIB contains optimized general-purpose signal-processing routines for TI DSPs"
HOMEPAGE = "http://www.ti.com/tool/mathlib"
SECTION = "devel"
LICENSE = "BSD-3-Clause"

require ../includes/ti-paths.inc
require ../includes/ti-staging.inc
require ../includes/ti-unpack.inc

COMPATIBLE_MACHINE = "omap-a15|keystone"

SRC_URI = "http://software-dl.ti.com/sdoemb/sdoemb_public_sw/mathlib/${PV}/exports/${BINFILE};name=mathlib"

S = "${WORKDIR}/mathlib-c66x-${PV}"

BINFILE = "mathlib_c66x_${PV}_Linux.bin"
TI_BIN_UNPK_ARGS = "--mode silent --prefix ${S}"
TI_BIN_UNPK_CMDS = ""

do_install() {
    CP_ARGS="-Prf --preserve=mode,timestamps --no-preserve=ownership"
    install -d ${D}${MATHLIB_C66_INSTALL_DIR_RECIPE}
    cp ${CP_ARGS} ${S}/* ${D}${MATHLIB_C66_INSTALL_DIR_RECIPE}
}

ALLOW_EMPTY_${PN} = "1"
FILES_${PN}-dev += "${MATHLIB_C66_INSTALL_DIR_RECIPE}"

INSANE_SKIP_${PN}-dev = "arch"
