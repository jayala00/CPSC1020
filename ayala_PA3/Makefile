# Jonathan Ayala
# CPSC 1020-002
# PA3
# ayala

# ******************************************************** #
#	General Purpose C/C++ Makefile
# ******************************************************** #

# Output Config
TARGET :=driver
OBJDIR :=bin/

# Compiler bin
CC 		 :=g++
CFLAGS :=-Wall -Wextra -Weffc++ -pedantic -std=c++11 -g
LFLAGS :=-lm

# Find all possible source files
CPP_SRCS := $(shell find * -type f -name '*.cpp')
HDRS 		 := $(shell find * -type f -name '*.h')
OBJS     := $(filter %.o, $(patsubst %.cpp, $(OBJDIR)%.o, $(CPP_SRCS)))

# Link all built objects
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

$(OBJDIR)%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

which:
	@echo "FOUND C++ SOURCES: ${CPP_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)
	rm -f "sharpen_100.ppm"
	rm -f "binary_100.ppm"
	rm -f "grayscale_100.ppm"
	rm -f "sepia_100_ec.ppm"
	rm -f "blur_100.ppm"
	rm -f "horizontal_100.ppm"
	rm -f "vertical_100.ppm"
	rm -f "shar_bin_hf_100.ppm"
	rm -f "shar_sep_vf_100.ppm"
	rm -f "shar_gs_hf_100.ppm"
	rm -f "blur_gs_vf_100.ppm"
	rm -f "blur_bin_hf_100.ppm"
	rm -f "blur_sep_vf_100.ppm"
	rm -f "stud_creation_100.ppm"
run:
		./$(TARGET) input.ppm
