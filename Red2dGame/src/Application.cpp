#include <RedEngine.h>
#include <Gui.h>

class TestGame : public RedEngine {
public:
	virtual void start() override {
	}

	virtual void update() override {
	}

	virtual void render() override {
	}
};

int main() {
	TestGame t;

	t.init(1280, 720, "hello", CameraType::Orthographic);
	t.start();
}