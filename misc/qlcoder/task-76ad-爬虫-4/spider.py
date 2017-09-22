# -*- coding: utf-8 -*-
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

accounts = []
for line in open('163.txt', 'r'):
	ep = line.split('----')
	accounts.append((ep[0], ep[1]))


fout = open('out.txt', 'w')


def one_by_one(driver, email, password):
	driver.get("http://mail.163.com")
	driver.find_element_by_id('idInput').send_keys(email[:-8])
	driver.find_element_by_id('pwdInput').send_keys(password+Keys.RETURN)
	driver.get("http://reg.163.com/account/accountInfo.jsp")
	elem = driver.find_element_by_xpath('/html/body/div[3]/div[2]/div[2]/ul[1]/li[2]')
	fout.write('%s,%s\n'%(email, elem.text[3:]))
	print('%s,%s'%(email, elem.text[3:]))


for (email, password) in accounts:
	try:
		driver = webdriver.Chrome()
		one_by_one(driver, email, password)
	except e:
		pass
	finally:
		driver.close()
	# break
