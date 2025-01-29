CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -ldpp -lsqlite3  # Aqui incluímos -ldpp e -lsqlite3

SRC_DIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
TARGET = $(BUILD_DIR)/disconomy

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)  # Garante que a pasta build existe
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Cria diretórios necessários
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)