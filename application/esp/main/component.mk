#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)
COMPONENT_EMBED_TXTFILES := certs/private_key.pem

ifndef IDF_CI_BUILD
# Print an error if the certificate/key files are missing
$(COMPONENT_PATH)/certs/private_key.pem:
	@echo "Missing PEM file $@. This file identifies the ESP32 to Google Cloud IoT Core for the example, see README for details."
	exit 1
else  # IDF_CI_BUILD
# this case is for the internal Continuous Integration build which
# compiles all examples. Add some dummy certs so the example can
# compile (even though it won't work)
$(COMPONENT_PATH)/certs/private_key.pem:
	echo "Dummy certificate data for continuous integration" > $@
endif
