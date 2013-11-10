#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  serialize.py
#  
#  Copyright 2013 tusharmakkar08 <tusharmakkar08@tusharmakkar08-Satellite-C660>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
# 

# Importing modules
import cPickle 

_end = '_end_'
# Implementation of Trie using Dictionaries in python
def make_trie(words):
	root=dict()
	for i in words :
		cd=root
		for letter in i:
			cd=cd.setdefault(letter,{})
		cd=cd.setdefault(_end,_end)
	return root

def in_trie(trie,word):
	cd=trie
	for letter in word:
		if letter in cd:
			cd=cd[letter]
		else:
			return False
	else:
		if _end in cd:
			return True
		else:
			return False

try:
	# Getting Data Back from Secondary file  So avoids makin trie again and again
	newt=open("result1.txt",'r')
	print "Fetching Result 1 from secondary memory ... "
	TR=cPickle.load(newt)
	newt.close()
except IOError:
	# Opening Data File
	print "Making of trie for result1"
	f=open("160million.txt")
	List=f.readlines()
	f.close()
	inp=[]
	# Code to remove \n from the file
	for i in List[:5000000]:
		k=i.strip()
		if k!='':
			inp.append(k.lower())
	del List
	TR=make_trie(inp)
	del inp
	# Dumping data into file 
	newres=open("result1.txt",'w')
	cPickle.dump(TR,newres)
	newres.close()
kiti=1
while kiti==1:
	kiti+=1
	r=raw_input("Enter string or -1 to exit\n")
	if r=="-1":
		break
	else:
		kit=r.lower()
		if in_trie(TR,kit):
			print "Found"
		else:
			del TR
			try:
				# Getting Data Back from Secondary file  So avoids makin trie again and again
				newt=open("result2.txt",'r')
				print "Fetching Result 2 from secondary memory ... "
				TR=cPickle.load(newt)
				newt.close()
			except IOError:
				# Opening Data File
				print "Making of trie for result 2"
				f=open("160million.txt")
				List=f.readlines()
				f.close()
				inp=[]
				# Code to remove \n from the file
				for i in List[5000000:10000000]:
					k=i.strip()
					if k!='':
						inp.append(k.lower())
				del List
				TR=make_trie(inp)
				del inp
				# Dumping data into file 
				newres=open("result2.txt",'w')
				cPickle.dump(TR,newres)
				newres.close()
			if in_trie(TR,kit):
				print "Found"
			else:
				del TR
				try:
					# Getting Data Back from Secondary file  So avoids makin trie again and again
					newt=open("result3.txt",'r')
					print "Fetching Result 3 from secondary memory ... "
					TR=cPickle.load(newt)
					newt.close()
				except IOError:
					# Opening Data File
					print "Making of trie for result 3"
					f=open("160million.txt")
					List=f.readlines()
					f.close()
					inp=[]
					# Code to remove \n from the file
					for i in List[10000000:]:
						k=i.strip()
						if k!='':
							inp.append(k.lower())
					del List
					TR=make_trie(inp)
					del inp
					# Dumping data into file 
					newres=open("result3.txt",'w')
					cPickle.dump(TR,newres)
					newres.close()
				if in_trie(TR,kit):
					print "Found"
				else:
					del TR
					print "Not Found"
					f.close()
