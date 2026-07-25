#!/usr/bin/env python3
import sys


def main():
    initial = [int(x) for x in sys.argv[1:]]
    a = list(initial)
    b = []
    ops = [line.strip() for line in sys.stdin if line.strip()]

    for op in ops:
        try:
            if op == "sa":
                if len(a) >= 2:
                    a[0], a[1] = a[1], a[0]
            elif op == "sb":
                if len(b) >= 2:
                    b[0], b[1] = b[1], b[0]
            elif op == "ss":
                if len(a) >= 2:
                    a[0], a[1] = a[1], a[0]
                if len(b) >= 2:
                    b[0], b[1] = b[1], b[0]
            elif op == "pa":
                if b:
                    a.insert(0, b.pop(0))
            elif op == "pb":
                if a:
                    b.insert(0, a.pop(0))
            elif op == "ra":
                if a:
                    a.append(a.pop(0))
            elif op == "rb":
                if b:
                    b.append(b.pop(0))
            elif op == "rr":
                if a:
                    a.append(a.pop(0))
                if b:
                    b.append(b.pop(0))
            elif op == "rra":
                if a:
                    a.insert(0, a.pop())
            elif op == "rrb":
                if b:
                    b.insert(0, b.pop())
            elif op == "rrr":
                if a:
                    a.insert(0, a.pop())
                if b:
                    b.insert(0, b.pop())
            else:
                print(f"OPERACAO DESCONHECIDA: '{op}'")
                sys.exit(1)
        except Exception as e:
            print(f"ERRO ao processar '{op}': {e}")
            sys.exit(1)

    is_sorted = a == sorted(initial)
    print(f"Total de operacoes: {len(ops)}")
    print(f"Tamanho stack a: {len(a)} | Tamanho stack b: {len(b)}")
    print(f"Stack b vazia no final: {'OK' if not b else 'FALHOU - b nao esta vazia!'}")
    print(f"Stack a ordenada: {'OK' if is_sorted else 'FALHOU'}")
    if not is_sorted:
        print(f"Esperado: {sorted(initial)}")
        print(f"Obtido:   {a}")


if __name__ == "__main__":
    main()
