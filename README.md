# CMPUT 350 Lab 3 Prep

[Instructions](https://uofa-cmput350.github.io/materials/lab/3/prep.html)

```
Consider the following question while implementing your UniquePtr<T>: suppose I take a const (lvalue) reference to a UniquePtr<T> like so:

void f(const UniquePtr<T>& x)
{
    // Can I modify the member fields of x's owned object here?
}
Should or shouldn't I be able to modify the member fields of the owned object inside f? If you want a UniquePtr which disallows modification to the stored object, how can you do this?
```

Yes, you can modify the fields of the owned x object, as the owned object itself is not declared const, only the UniquePtr wrapping it.  

If you want to make the owned object const as well, you can write it as const UniquePtr<const T>& x.
