#!/usr/bin/env bash

gvpr -f closure.gprv closure.gv > _res.dot
dot -Tpng _res.dot -o result.png
