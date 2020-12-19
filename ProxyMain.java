import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

interface HelloInterface {
    void sayHello();
}

class Hello implements HelloInterface {
    @Override
    public void sayHello() {
        System.out.println("Hello zhanghao!");
    }
}

class ProxyHandler implements InvocationHandler {
    private Object object;

    public ProxyHandler(Object object) {
        this.object = object;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("Before invoke " + method.getName());
        method.invoke(object, args);
        System.out.println("After invoke " + method.getName());
        return null;
    }
}

public class ProxyMain {
    public static void main(String[] args) {
        HelloInterface hello = new Hello();
        InvocationHandler handler = new ProxyHandler(hello);
        HelloInterface proxyHello = (HelloInterface) Proxy.newProxyInstance(hello.getClass().getClassLoader(),
                hello.getClass().getInterfaces(), handler);
        proxyHello.sayHello();
    }
}
