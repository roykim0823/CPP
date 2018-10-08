#include <memory>
typedef int Data;

namespace HandleClassExample {

	class ExampleImpl {
	public:
		ExampleImpl(const Data &data)
			:data(data)
		{}
		Data getData() const { return data; }
	private:
		Data data;
	};

	class Example {
	public:
		Example(const Data &data)
			:pImpl(std::make_shared<ExampleImpl>(data))
		{}
		Data getData() const { return pImpl->getData(); }
	private:
		std::shared_ptr<ExampleImpl> pImpl;
	};
}

namespace InterfaceClassExample {

	class Example {
	public:
		virtual ~Example() = default;
		virtual Data getData() const = 0;
		static std::shared_ptr<Example> create(const Data &data) {
			return std::make_shared<ExampleImpl>(data);
		}
	};

	class ExampleImpl : public Example {
	public:
		ExampleImpl(const Data &data)
			:data(data)
		{}
		Data getData() const { return data; }
	private:
		Data data;
	};
}
