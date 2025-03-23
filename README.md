## Install AstraVer Toolset (Why3 + Frama-C + AstraVer plugin)

```console
$ opam repo add ispras https://forge.ispras.ru/git/astraver.opam-repository.git
$ opam update
$ opam install astraver
$ opam install alt-ergo
$ why3 config --detect
```

## Install CVC4 Theorem Prover
Some programs in can only be proved with CVC4 solver:
```console
$ wget https://github.com/CVC4/CVC4-archived/releases/download/1.8/cvc4-1.8-x86_64-linux-opt
$ cp cvc4-1.8-x86_64-linux-opt /usr/local/bin/cvc4
$ chmod +x /usr/local/bin/cvc4
```

## Open Frama-C Verification Session
```console
$ frama-c -av frama-c/<file.c>
```

## Open Why3 Verification Session
```console
$ why3 why3/<file.c>
```

