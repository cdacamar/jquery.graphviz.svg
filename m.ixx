#include <utility>
export module m;

export {

template <typename T>
constexpr T pi = 3.14159;

template <typename...>
using void_t = void;

template <typename T, int... I>
struct holder { using type = T; int a[sizeof...(I)] = { I... }; };

template <typename T, int... I>
using holder_t = typename holder<T, I...>::type;

template <typename T, template <typename,typename...> typename C>
struct specialized {
  template <typename... Us>
  using type = C<T, Us...>;
};

template <typename T, template <typename,typename...> typename C, typename... Us>
using specialized_t = typename specialized<T, C>::template type<Us...>;

template <typename T>
struct container {
  T* begin() const;
  T* end() const;
};

template <typename T>
void h() {
  for (auto&& e : container<T>{}) {
    h<T>();
    static_cast<const int*>(e);
    const_cast<const int*>(e);
    reinterpret_cast<const int*>(e);
    dynamic_cast<const int*>(e);
    auto i = T(10);
    (void) i;
    (void*)i;
  }
}

template <typename F>
class invoker {
  invoker(F f)
    : func{ std::move(f) }, a(10) { }

  invoker() = default;
  invoker(const invoker&) = default;
  invoker(invoker&&) = default;

  invoker(int): func{}, a{std::forward<int&&>(10)} { }

  template <typename... Ts>
  auto invoke(Ts&&... args)
  {
    return func(std::forward<Ts>(args)...);
  }
  F func;
  int a = std::forward<int&&>(10);
};
using int_t = int;
typedef int my_int;
using func_t = void(*)(int,char,...);
typedef void(*my_func_t)(int,void*,...);

void printf(...);

template <typename T, int N>
int f(int a, char b) {
  int a;
  std::forward<int&&>(10);
  for (int i = 0; i != 10; ++i) {
    printf("%d ", i);
  }
  return a;
}

}

namespace impl {
  namespace structs {
    struct U {
      U(int): a{} { }
      constexpr [[nodiscard]] U(): a{} { }
      constexpr U(U&&) = default;
      U(const U&) = default;
      U(int,char,void*,U*) { }
      int a;
      ~U() = default;
    };
  }
  namespace templates {
    template <typename...>
    struct templ { structs::U u; };
  }
}

export {

enum class color : unsigned int {
  red = 0x0f,
  blue = 0xa0,
  green = 0xf0,
};

enum class count : int {
  one = 1,
  two = 2,
  three = 3,
};

enum class implicit {
  implicit_1,
  implicit_2,
  implicit_3,
  implicit_4,
};

template <typename T>
void switcher(implicit i) {
  switch (T t { }; i) {
  case implicit::implicit_1:
    {
      for (auto&& e : container<T>{}) { }
    }
    break;
  case implicit::implicit_2:
    break;
  case implicit::implicit_3:
    break;
  case implicit::implicit_4:
    break;
  case 0:
  default:
   ;
  }
}

namespace m {
  struct S { };
  void f(const int* const);
  void f(char*const*);
  void* g(const int);
  S* g();
  S* g(S**const, S);
}

namespace n {
  void f();
  int g();
  long double h();
  float i();
  using namespace impl::structs;
  impl::structs::U j(U, U);
  impl::templates::templ<int, char, unsigned int, double, wchar_t> k();
}

namespace o {
  struct S {
    virtual void f() const = 0;
    virtual int f(int) volatile const = 0;
    virtual int f(char) volatile const & = 0;
    virtual int f(char) volatile const && = 0;
    static constexpr int i = 10;
  };
  void f(int&);
  void f(int&&);
  const int& f(char&);
  S& g(S&);
  S&& g(const S&, S&, S&&, const S&&);
}

namespace p {
  inline int (* f())(int) { return { }; }
  int f(void(char));
}

namespace q {
  using o::f;
  struct A { };
  struct B { };
  struct C { };
  struct D : virtual A, private B, C { };
}

struct S {
  template <typename T>
  struct void_t { };
  int a;
  char b;
};

using SS = S;

}
