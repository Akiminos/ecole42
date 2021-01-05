#!/bin/sh

ifconfig -a ether | grep ether | tr -d "[[:blank:]]" | cut -c 6-30
