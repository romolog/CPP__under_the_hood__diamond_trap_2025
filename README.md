# Diamond trap

I explored multiple inheritance and solved the Diamond Problem to control inheritance from both parent classes without modifying them.

In simple terms, I enabled control over the values of fields inherited by the child class. The solution uses a proxy class, that inherits from only one parent. The proxy is nested within the child class. The child class can then override field values using the values stored in the proxy.

---

### System Requirements

- Linux (Ubuntu)
- g++
- make

---

### Build

```bash
git clone https://github.com/romolog/CPP__under_the_hood__diamond_trap_2025.git diamond_trap;
cd diamond_trap/diamond_trap;
make;
```

### Run
```bash
./diamond;
```
