# __LWFSM : *Lightweight FSM management system for embedded systems*__

The documentation is handled with [Sphinx](https://www.sphinx-doc.org/en/master/index.html) and [Read the Docs](https://readthedocs.org/).

The generated documentation is hosted on the [GitHub Pages](https://fred-r-perso.github.io/lwfsm/).

## Local build
```
fred@fred-N53Jl:~/lwfsm/lwfsm/docs$ make clean && make html
...
Build finished. The HTML pages are in _build/html.
```

## Github updates

This is handled via 'build_docs.sh'.

The 'gh-pages' site is updated when a commit is pushed on 'develop' or 'master'.

## Required tools

- [Doxygen](https://sourceforge.net/projects/doxygen/) 1.8.x to build the documentation
- [Graphviz](https://graphviz.org/download/) to create graphs in the documentation
