# chess_db
Chess PGN parser and kind of an in-memory database

Some notes:
0. Very incomplete project!!! Code is not really clean yet, this is just a home project!
1. Build with VS2019 in release mode
2. Command line format is:
   chess_db <settings.ini> <positions.ini>
3. Please see included chess_db.ini and start_pos.ini for examples of config file format.
4. Log file is written to the working directory of the executable
5. I typically run this using PGN files found at https://www.kingbase-chess.net/

Log file output for a 140,000+ game PGN file included below.
Results of 2 searches (one very standard position, one rare position) together with how White/Black fared are at the bottom.
Also at the bottom are some function timing measurements.


[2019/06/22 01:28:57]
Logger initialized
checkCommandLine(argc: 3)
readSettingsFile(iniFilePath: chess_db.ini)
Opened settings file
readPositionsFile(iniFilePath: start_pos.ini)
Opened positions file
GameParser::parsePGN
# lines: 1000, gameVec sz: 49
# lines: 2000, gameVec sz: 97
# lines: 3000, gameVec sz: 146
# lines: 4000, gameVec sz: 192
# lines: 5000, gameVec sz: 241
# lines: 6000, gameVec sz: 290
# lines: 7000, gameVec sz: 339
# lines: 8000, gameVec sz: 387
# lines: 9000, gameVec sz: 435
# lines: 10000, gameVec sz: 484
# lines: 11000, gameVec sz: 532
# lines: 12000, gameVec sz: 581
# lines: 13000, gameVec sz: 629
# lines: 14000, gameVec sz: 678
# lines: 15000, gameVec sz: 728
# lines: 16000, gameVec sz: 776
# lines: 17000, gameVec sz: 824
# lines: 18000, gameVec sz: 873
# lines: 19000, gameVec sz: 924
# lines: 20000, gameVec sz: 975
# lines: 21000, gameVec sz: 1022
# lines: 22000, gameVec sz: 1073
# lines: 23000, gameVec sz: 1123
# lines: 24000, gameVec sz: 1173
# lines: 25000, gameVec sz: 1222
# lines: 26000, gameVec sz: 1272
# lines: 27000, gameVec sz: 1322
# lines: 28000, gameVec sz: 1371
# lines: 29000, gameVec sz: 1420
# lines: 30000, gameVec sz: 1469
# lines: 31000, gameVec sz: 1520
# lines: 32000, gameVec sz: 1571
# lines: 33000, gameVec sz: 1622
# lines: 34000, gameVec sz: 1674
# lines: 35000, gameVec sz: 1723
# lines: 36000, gameVec sz: 1773
# lines: 37000, gameVec sz: 1825
# lines: 38000, gameVec sz: 1875
# lines: 39000, gameVec sz: 1927
# lines: 40000, gameVec sz: 1976
# lines: 41000, gameVec sz: 2027
# lines: 42000, gameVec sz: 2077
# lines: 43000, gameVec sz: 2127
# lines: 44000, gameVec sz: 2176
# lines: 45000, gameVec sz: 2225
# lines: 46000, gameVec sz: 2273
# lines: 47000, gameVec sz: 2322
# lines: 48000, gameVec sz: 2371
# lines: 49000, gameVec sz: 2421
# lines: 50000, gameVec sz: 2473
# lines: 51000, gameVec sz: 2523
# lines: 52000, gameVec sz: 2574
# lines: 53000, gameVec sz: 2624
# lines: 54000, gameVec sz: 2674
# lines: 55000, gameVec sz: 2725
# lines: 56000, gameVec sz: 2774
# lines: 57000, gameVec sz: 2824
# lines: 58000, gameVec sz: 2873
# lines: 59000, gameVec sz: 2922
# lines: 60000, gameVec sz: 2972
# lines: 61000, gameVec sz: 3021
# lines: 62000, gameVec sz: 3069
# lines: 63000, gameVec sz: 3117
# lines: 64000, gameVec sz: 3165
# lines: 65000, gameVec sz: 3215
# lines: 66000, gameVec sz: 3265
# lines: 67000, gameVec sz: 3314
# lines: 68000, gameVec sz: 3363
# lines: 69000, gameVec sz: 3412
# lines: 70000, gameVec sz: 3460
# lines: 71000, gameVec sz: 3508
# lines: 72000, gameVec sz: 3560
# lines: 73000, gameVec sz: 3608
# lines: 74000, gameVec sz: 3656
# lines: 75000, gameVec sz: 3706
# lines: 76000, gameVec sz: 3757
# lines: 77000, gameVec sz: 3810
# lines: 78000, gameVec sz: 3861
# lines: 79000, gameVec sz: 3911
# lines: 80000, gameVec sz: 3963
# lines: 81000, gameVec sz: 4013
# lines: 82000, gameVec sz: 4063
# lines: 83000, gameVec sz: 4114
# lines: 84000, gameVec sz: 4163
# lines: 85000, gameVec sz: 4212
# lines: 86000, gameVec sz: 4260
# lines: 87000, gameVec sz: 4312
# lines: 88000, gameVec sz: 4363
# lines: 89000, gameVec sz: 4414
# lines: 90000, gameVec sz: 4461
# lines: 91000, gameVec sz: 4512
# lines: 92000, gameVec sz: 4562
# lines: 93000, gameVec sz: 4613
# lines: 94000, gameVec sz: 4662
[2019/06/22 01:28:58]
# lines: 95000, gameVec sz: 4713
# lines: 96000, gameVec sz: 4762
# lines: 97000, gameVec sz: 4815
# lines: 98000, gameVec sz: 4865
# lines: 99000, gameVec sz: 4914
# lines: 100000, gameVec sz: 4965
# lines: 101000, gameVec sz: 5015
# lines: 102000, gameVec sz: 5064
# lines: 103000, gameVec sz: 5115
# lines: 104000, gameVec sz: 5164
# lines: 105000, gameVec sz: 5214
# lines: 106000, gameVec sz: 5263
# lines: 107000, gameVec sz: 5312
# lines: 108000, gameVec sz: 5361
# lines: 109000, gameVec sz: 5412
# lines: 110000, gameVec sz: 5463
# lines: 111000, gameVec sz: 5511
# lines: 112000, gameVec sz: 5562
# lines: 113000, gameVec sz: 5611
# lines: 114000, gameVec sz: 5660
# lines: 115000, gameVec sz: 5711
# lines: 116000, gameVec sz: 5762
# lines: 117000, gameVec sz: 5814
# lines: 118000, gameVec sz: 5863
# lines: 119000, gameVec sz: 5913
# lines: 120000, gameVec sz: 5963
# lines: 121000, gameVec sz: 6011
# lines: 122000, gameVec sz: 6063
# lines: 123000, gameVec sz: 6116
# lines: 124000, gameVec sz: 6166
# lines: 125000, gameVec sz: 6216
# lines: 126000, gameVec sz: 6266
# lines: 127000, gameVec sz: 6316
# lines: 128000, gameVec sz: 6365
# lines: 129000, gameVec sz: 6415
# lines: 130000, gameVec sz: 6465
# lines: 131000, gameVec sz: 6515
# lines: 132000, gameVec sz: 6566
# lines: 133000, gameVec sz: 6617
# lines: 134000, gameVec sz: 6668
# lines: 135000, gameVec sz: 6719
# lines: 136000, gameVec sz: 6770
# lines: 137000, gameVec sz: 6821
# lines: 138000, gameVec sz: 6872
# lines: 139000, gameVec sz: 6920
# lines: 140000, gameVec sz: 6971
# lines: 141000, gameVec sz: 7020
# lines: 142000, gameVec sz: 7069
# lines: 143000, gameVec sz: 7121
# lines: 144000, gameVec sz: 7170
# lines: 145000, gameVec sz: 7221
# lines: 146000, gameVec sz: 7270
# lines: 147000, gameVec sz: 7320
# lines: 148000, gameVec sz: 7370
# lines: 149000, gameVec sz: 7421
# lines: 150000, gameVec sz: 7471
# lines: 151000, gameVec sz: 7522
# lines: 152000, gameVec sz: 7573
# lines: 153000, gameVec sz: 7626
# lines: 154000, gameVec sz: 7676
# lines: 155000, gameVec sz: 7727
# lines: 156000, gameVec sz: 7776
# lines: 157000, gameVec sz: 7825
# lines: 158000, gameVec sz: 7874
# lines: 159000, gameVec sz: 7924
# lines: 160000, gameVec sz: 7974
# lines: 161000, gameVec sz: 8025
# lines: 162000, gameVec sz: 8076
# lines: 163000, gameVec sz: 8127
# lines: 164000, gameVec sz: 8179
# lines: 165000, gameVec sz: 8230
# lines: 166000, gameVec sz: 8280
# lines: 167000, gameVec sz: 8330
# lines: 168000, gameVec sz: 8378
# lines: 169000, gameVec sz: 8427
# lines: 170000, gameVec sz: 8478
# lines: 171000, gameVec sz: 8528
# lines: 172000, gameVec sz: 8577
# lines: 173000, gameVec sz: 8626
# lines: 174000, gameVec sz: 8674
# lines: 175000, gameVec sz: 8724
# lines: 176000, gameVec sz: 8774
# lines: 177000, gameVec sz: 8825
# lines: 178000, gameVec sz: 8874
# lines: 179000, gameVec sz: 8925
# lines: 180000, gameVec sz: 8975
# lines: 181000, gameVec sz: 9024
# lines: 182000, gameVec sz: 9074
# lines: 183000, gameVec sz: 9123
# lines: 184000, gameVec sz: 9174
# lines: 185000, gameVec sz: 9224
# lines: 186000, gameVec sz: 9274
# lines: 187000, gameVec sz: 9323
# lines: 188000, gameVec sz: 9373
# lines: 189000, gameVec sz: 9422
# lines: 190000, gameVec sz: 9470
# lines: 191000, gameVec sz: 9520
# lines: 192000, gameVec sz: 9571
# lines: 193000, gameVec sz: 9622
# lines: 194000, gameVec sz: 9673
# lines: 195000, gameVec sz: 9720
# lines: 196000, gameVec sz: 9770
# lines: 197000, gameVec sz: 9821
# lines: 198000, gameVec sz: 9869
# lines: 199000, gameVec sz: 9918
# lines: 200000, gameVec sz: 9969
# lines: 201000, gameVec sz: 10019
# lines: 202000, gameVec sz: 10071
# lines: 203000, gameVec sz: 10122
# lines: 204000, gameVec sz: 10173
# lines: 205000, gameVec sz: 10223
# lines: 206000, gameVec sz: 10274
# lines: 207000, gameVec sz: 10324
# lines: 208000, gameVec sz: 10376
# lines: 209000, gameVec sz: 10424
# lines: 210000, gameVec sz: 10472
# lines: 211000, gameVec sz: 10521
# lines: 212000, gameVec sz: 10571
# lines: 213000, gameVec sz: 10622
# lines: 214000, gameVec sz: 10672
# lines: 215000, gameVec sz: 10721
# lines: 216000, gameVec sz: 10770
# lines: 217000, gameVec sz: 10820
# lines: 218000, gameVec sz: 10869
# lines: 219000, gameVec sz: 10919
# lines: 220000, gameVec sz: 10968
# lines: 221000, gameVec sz: 11018
# lines: 222000, gameVec sz: 11066
# lines: 223000, gameVec sz: 11116
# lines: 224000, gameVec sz: 11165
# lines: 225000, gameVec sz: 11215
# lines: 226000, gameVec sz: 11265
# lines: 227000, gameVec sz: 11313
# lines: 228000, gameVec sz: 11364
# lines: 229000, gameVec sz: 11414
# lines: 230000, gameVec sz: 11463
# lines: 231000, gameVec sz: 11512
# lines: 232000, gameVec sz: 11563
# lines: 233000, gameVec sz: 11612
# lines: 234000, gameVec sz: 11662
# lines: 235000, gameVec sz: 11711
# lines: 236000, gameVec sz: 11759
# lines: 237000, gameVec sz: 11809
# lines: 238000, gameVec sz: 11856
# lines: 239000, gameVec sz: 11905
# lines: 240000, gameVec sz: 11952
# lines: 241000, gameVec sz: 11999
# lines: 242000, gameVec sz: 12049
# lines: 243000, gameVec sz: 12099
# lines: 244000, gameVec sz: 12147
# lines: 245000, gameVec sz: 12194
# lines: 246000, gameVec sz: 12243
# lines: 247000, gameVec sz: 12291
# lines: 248000, gameVec sz: 12340
# lines: 249000, gameVec sz: 12386
# lines: 250000, gameVec sz: 12434
# lines: 251000, gameVec sz: 12482
# lines: 252000, gameVec sz: 12531
# lines: 253000, gameVec sz: 12581
# lines: 254000, gameVec sz: 12629
# lines: 255000, gameVec sz: 12678
# lines: 256000, gameVec sz: 12727
# lines: 257000, gameVec sz: 12776
# lines: 258000, gameVec sz: 12824
# lines: 259000, gameVec sz: 12873
# lines: 260000, gameVec sz: 12922
[2019/06/22 01:28:59]
# lines: 261000, gameVec sz: 12970
# lines: 262000, gameVec sz: 13017
# lines: 263000, gameVec sz: 13067
# lines: 264000, gameVec sz: 13116
# lines: 265000, gameVec sz: 13167
# lines: 266000, gameVec sz: 13216
# lines: 267000, gameVec sz: 13265
# lines: 268000, gameVec sz: 13315
# lines: 269000, gameVec sz: 13364
# lines: 270000, gameVec sz: 13415
# lines: 271000, gameVec sz: 13465
# lines: 272000, gameVec sz: 13514
# lines: 273000, gameVec sz: 13564
# lines: 274000, gameVec sz: 13615
# lines: 275000, gameVec sz: 13666
# lines: 276000, gameVec sz: 13715
# lines: 277000, gameVec sz: 13767
# lines: 278000, gameVec sz: 13819
# lines: 279000, gameVec sz: 13868
# lines: 280000, gameVec sz: 13915
# lines: 281000, gameVec sz: 13966
# lines: 282000, gameVec sz: 14016
# lines: 283000, gameVec sz: 14066
# lines: 284000, gameVec sz: 14117
# lines: 285000, gameVec sz: 14167
# lines: 286000, gameVec sz: 14217
# lines: 287000, gameVec sz: 14265
# lines: 288000, gameVec sz: 14314
# lines: 289000, gameVec sz: 14365
# lines: 290000, gameVec sz: 14416
# lines: 291000, gameVec sz: 14464
# lines: 292000, gameVec sz: 14513
# lines: 293000, gameVec sz: 14563
# lines: 294000, gameVec sz: 14614
# lines: 295000, gameVec sz: 14665
# lines: 296000, gameVec sz: 14715
# lines: 297000, gameVec sz: 14765
# lines: 298000, gameVec sz: 14815
# lines: 299000, gameVec sz: 14862
# lines: 300000, gameVec sz: 14911
# lines: 301000, gameVec sz: 14962
# lines: 302000, gameVec sz: 15012
# lines: 303000, gameVec sz: 15059
# lines: 304000, gameVec sz: 15110
# lines: 305000, gameVec sz: 15159
# lines: 306000, gameVec sz: 15208
# lines: 307000, gameVec sz: 15256
# lines: 308000, gameVec sz: 15308
# lines: 309000, gameVec sz: 15358
# lines: 310000, gameVec sz: 15409
# lines: 311000, gameVec sz: 15460
# lines: 312000, gameVec sz: 15510
# lines: 313000, gameVec sz: 15562
# lines: 314000, gameVec sz: 15614
# lines: 315000, gameVec sz: 15663
# lines: 316000, gameVec sz: 15714
# lines: 317000, gameVec sz: 15765
# lines: 318000, gameVec sz: 15816
# lines: 319000, gameVec sz: 15863
# lines: 320000, gameVec sz: 15913
# lines: 321000, gameVec sz: 15966
# lines: 322000, gameVec sz: 16016
# lines: 323000, gameVec sz: 16066
# lines: 324000, gameVec sz: 16117
# lines: 325000, gameVec sz: 16168
# lines: 326000, gameVec sz: 16220
# lines: 327000, gameVec sz: 16272
# lines: 328000, gameVec sz: 16323
# lines: 329000, gameVec sz: 16373
# lines: 330000, gameVec sz: 16423
# lines: 331000, gameVec sz: 16474
# lines: 332000, gameVec sz: 16522
# lines: 333000, gameVec sz: 16570
# lines: 334000, gameVec sz: 16620
# lines: 335000, gameVec sz: 16668
# lines: 336000, gameVec sz: 16720
# lines: 337000, gameVec sz: 16768
# lines: 338000, gameVec sz: 16818
# lines: 339000, gameVec sz: 16867
# lines: 340000, gameVec sz: 16917
# lines: 341000, gameVec sz: 16968
# lines: 342000, gameVec sz: 17019
# lines: 343000, gameVec sz: 17069
# lines: 344000, gameVec sz: 17117
# lines: 345000, gameVec sz: 17167
# lines: 346000, gameVec sz: 17218
# lines: 347000, gameVec sz: 17268
# lines: 348000, gameVec sz: 17318
# lines: 349000, gameVec sz: 17367
# lines: 350000, gameVec sz: 17417
# lines: 351000, gameVec sz: 17467
# lines: 352000, gameVec sz: 17517
# lines: 353000, gameVec sz: 17567
# lines: 354000, gameVec sz: 17617
# lines: 355000, gameVec sz: 17666
# lines: 356000, gameVec sz: 17715
# lines: 357000, gameVec sz: 17764
# lines: 358000, gameVec sz: 17814
# lines: 359000, gameVec sz: 17864
# lines: 360000, gameVec sz: 17914
# lines: 361000, gameVec sz: 17964
# lines: 362000, gameVec sz: 18013
# lines: 363000, gameVec sz: 18064
# lines: 364000, gameVec sz: 18113
# lines: 365000, gameVec sz: 18161
# lines: 366000, gameVec sz: 18210
# lines: 367000, gameVec sz: 18259
# lines: 368000, gameVec sz: 18309
# lines: 369000, gameVec sz: 18359
# lines: 370000, gameVec sz: 18409
# lines: 371000, gameVec sz: 18455
# lines: 372000, gameVec sz: 18505
# lines: 373000, gameVec sz: 18556
# lines: 374000, gameVec sz: 18608
# lines: 375000, gameVec sz: 18657
# lines: 376000, gameVec sz: 18707
# lines: 377000, gameVec sz: 18758
# lines: 378000, gameVec sz: 18808
# lines: 379000, gameVec sz: 18856
# lines: 380000, gameVec sz: 18907
# lines: 381000, gameVec sz: 18958
# lines: 382000, gameVec sz: 19009
# lines: 383000, gameVec sz: 19060
# lines: 384000, gameVec sz: 19109
# lines: 385000, gameVec sz: 19160
# lines: 386000, gameVec sz: 19210
# lines: 387000, gameVec sz: 19259
# lines: 388000, gameVec sz: 19307
# lines: 389000, gameVec sz: 19356
# lines: 390000, gameVec sz: 19405
# lines: 391000, gameVec sz: 19456
# lines: 392000, gameVec sz: 19504
# lines: 393000, gameVec sz: 19555
# lines: 394000, gameVec sz: 19606
# lines: 395000, gameVec sz: 19658
# lines: 396000, gameVec sz: 19707
# lines: 397000, gameVec sz: 19759
# lines: 398000, gameVec sz: 19809
# lines: 399000, gameVec sz: 19859
# lines: 400000, gameVec sz: 19908
# lines: 401000, gameVec sz: 19958
# lines: 402000, gameVec sz: 20008
# lines: 403000, gameVec sz: 20060
# lines: 404000, gameVec sz: 20111
# lines: 405000, gameVec sz: 20162
# lines: 406000, gameVec sz: 20212
# lines: 407000, gameVec sz: 20262
# lines: 408000, gameVec sz: 20313
# lines: 409000, gameVec sz: 20363
# lines: 410000, gameVec sz: 20414
# lines: 411000, gameVec sz: 20466
# lines: 412000, gameVec sz: 20516
# lines: 413000, gameVec sz: 20566
# lines: 414000, gameVec sz: 20616
# lines: 415000, gameVec sz: 20666
# lines: 416000, gameVec sz: 20717
# lines: 417000, gameVec sz: 20768
# lines: 418000, gameVec sz: 20817
# lines: 419000, gameVec sz: 20868
# lines: 420000, gameVec sz: 20918
# lines: 421000, gameVec sz: 20968
# lines: 422000, gameVec sz: 21016
# lines: 423000, gameVec sz: 21064
# lines: 424000, gameVec sz: 21114
# lines: 425000, gameVec sz: 21164
# lines: 426000, gameVec sz: 21210
# lines: 427000, gameVec sz: 21260
# lines: 428000, gameVec sz: 21310
# lines: 429000, gameVec sz: 21360
# lines: 430000, gameVec sz: 21411
# lines: 431000, gameVec sz: 21460
# lines: 432000, gameVec sz: 21507
# lines: 433000, gameVec sz: 21559
# lines: 434000, gameVec sz: 21608
# lines: 435000, gameVec sz: 21657
# lines: 436000, gameVec sz: 21707
# lines: 437000, gameVec sz: 21757
# lines: 438000, gameVec sz: 21806
# lines: 439000, gameVec sz: 21856
# lines: 440000, gameVec sz: 21906
# lines: 441000, gameVec sz: 21957
# lines: 442000, gameVec sz: 22006
# lines: 443000, gameVec sz: 22058
# lines: 444000, gameVec sz: 22106
# lines: 445000, gameVec sz: 22156
# lines: 446000, gameVec sz: 22206
# lines: 447000, gameVec sz: 22256
# lines: 448000, gameVec sz: 22303
# lines: 449000, gameVec sz: 22351
# lines: 450000, gameVec sz: 22401
# lines: 451000, gameVec sz: 22453
# lines: 452000, gameVec sz: 22503
# lines: 453000, gameVec sz: 22553
# lines: 454000, gameVec sz: 22601
# lines: 455000, gameVec sz: 22647
# lines: 456000, gameVec sz: 22694
# lines: 457000, gameVec sz: 22743
# lines: 458000, gameVec sz: 22791
# lines: 459000, gameVec sz: 22840
# lines: 460000, gameVec sz: 22888
# lines: 461000, gameVec sz: 22937
# lines: 462000, gameVec sz: 22985
# lines: 463000, gameVec sz: 23033
# lines: 464000, gameVec sz: 23084
# lines: 465000, gameVec sz: 23133
# lines: 466000, gameVec sz: 23183
# lines: 467000, gameVec sz: 23232
# lines: 468000, gameVec sz: 23281
# lines: 469000, gameVec sz: 23331
# lines: 470000, gameVec sz: 23380
# lines: 471000, gameVec sz: 23431
# lines: 472000, gameVec sz: 23481
# lines: 473000, gameVec sz: 23532
# lines: 474000, gameVec sz: 23582
# lines: 475000, gameVec sz: 23632
# lines: 476000, gameVec sz: 23681
# lines: 477000, gameVec sz: 23728
# lines: 478000, gameVec sz: 23779
# lines: 479000, gameVec sz: 23830
# lines: 480000, gameVec sz: 23880
# lines: 481000, gameVec sz: 23931
# lines: 482000, gameVec sz: 23982
# lines: 483000, gameVec sz: 24033
# lines: 484000, gameVec sz: 24082
# lines: 485000, gameVec sz: 24133
# lines: 486000, gameVec sz: 24183
# lines: 487000, gameVec sz: 24234
# lines: 488000, gameVec sz: 24284
# lines: 489000, gameVec sz: 24335
# lines: 490000, gameVec sz: 24386
# lines: 491000, gameVec sz: 24436
# lines: 492000, gameVec sz: 24485
# lines: 493000, gameVec sz: 24534
# lines: 494000, gameVec sz: 24583
# lines: 495000, gameVec sz: 24635
# lines: 496000, gameVec sz: 24686
# lines: 497000, gameVec sz: 24734
# lines: 498000, gameVec sz: 24784
# lines: 499000, gameVec sz: 24833
# lines: 500000, gameVec sz: 24882
# lines: 501000, gameVec sz: 24934
# lines: 502000, gameVec sz: 24986
# lines: 503000, gameVec sz: 25035
[2019/06/22 01:29:00]
# lines: 504000, gameVec sz: 25086
# lines: 505000, gameVec sz: 25136
# lines: 506000, gameVec sz: 25184
# lines: 507000, gameVec sz: 25234
# lines: 508000, gameVec sz: 25283
# lines: 509000, gameVec sz: 25334
# lines: 510000, gameVec sz: 25383
# lines: 511000, gameVec sz: 25436
# lines: 512000, gameVec sz: 25487
# lines: 513000, gameVec sz: 25538
# lines: 514000, gameVec sz: 25589
# lines: 515000, gameVec sz: 25639
# lines: 516000, gameVec sz: 25691
# lines: 517000, gameVec sz: 25743
# lines: 518000, gameVec sz: 25795
# lines: 519000, gameVec sz: 25843
# lines: 520000, gameVec sz: 25894
# lines: 521000, gameVec sz: 25943
# lines: 522000, gameVec sz: 25991
# lines: 523000, gameVec sz: 26038
# lines: 524000, gameVec sz: 26087
# lines: 525000, gameVec sz: 26137
# lines: 526000, gameVec sz: 26188
# lines: 527000, gameVec sz: 26240
# lines: 528000, gameVec sz: 26291
# lines: 529000, gameVec sz: 26342
# lines: 530000, gameVec sz: 26392
# lines: 531000, gameVec sz: 26442
# lines: 532000, gameVec sz: 26491
# lines: 533000, gameVec sz: 26541
# lines: 534000, gameVec sz: 26591
# lines: 535000, gameVec sz: 26641
# lines: 536000, gameVec sz: 26691
# lines: 537000, gameVec sz: 26742
# lines: 538000, gameVec sz: 26790
# lines: 539000, gameVec sz: 26843
# lines: 540000, gameVec sz: 26894
# lines: 541000, gameVec sz: 26945
# lines: 542000, gameVec sz: 26994
# lines: 543000, gameVec sz: 27044
# lines: 544000, gameVec sz: 27095
# lines: 545000, gameVec sz: 27145
# lines: 546000, gameVec sz: 27195
# lines: 547000, gameVec sz: 27244
# lines: 548000, gameVec sz: 27295
# lines: 549000, gameVec sz: 27346
# lines: 550000, gameVec sz: 27395
# lines: 551000, gameVec sz: 27446
# lines: 552000, gameVec sz: 27495
# lines: 553000, gameVec sz: 27547
# lines: 554000, gameVec sz: 27596
# lines: 555000, gameVec sz: 27644
# lines: 556000, gameVec sz: 27694
# lines: 557000, gameVec sz: 27744
# lines: 558000, gameVec sz: 27794
# lines: 559000, gameVec sz: 27844
# lines: 560000, gameVec sz: 27893
# lines: 561000, gameVec sz: 27943
# lines: 562000, gameVec sz: 27994
# lines: 563000, gameVec sz: 28045
# lines: 564000, gameVec sz: 28095
# lines: 565000, gameVec sz: 28146
# lines: 566000, gameVec sz: 28197
# lines: 567000, gameVec sz: 28246
# lines: 568000, gameVec sz: 28296
# lines: 569000, gameVec sz: 28343
# lines: 570000, gameVec sz: 28392
# lines: 571000, gameVec sz: 28440
# lines: 572000, gameVec sz: 28490
# lines: 573000, gameVec sz: 28537
# lines: 574000, gameVec sz: 28587
# lines: 575000, gameVec sz: 28639
# lines: 576000, gameVec sz: 28689
# lines: 577000, gameVec sz: 28738
# lines: 578000, gameVec sz: 28789
# lines: 579000, gameVec sz: 28837
# lines: 580000, gameVec sz: 28884
# lines: 581000, gameVec sz: 28936
# lines: 582000, gameVec sz: 28985
# lines: 583000, gameVec sz: 29036
# lines: 584000, gameVec sz: 29087
# lines: 585000, gameVec sz: 29137
# lines: 586000, gameVec sz: 29186
# lines: 587000, gameVec sz: 29237
# lines: 588000, gameVec sz: 29288
# lines: 589000, gameVec sz: 29338
# lines: 590000, gameVec sz: 29387
# lines: 591000, gameVec sz: 29436
# lines: 592000, gameVec sz: 29486
# lines: 593000, gameVec sz: 29535
# lines: 594000, gameVec sz: 29585
# lines: 595000, gameVec sz: 29635
# lines: 596000, gameVec sz: 29685
# lines: 597000, gameVec sz: 29733
# lines: 598000, gameVec sz: 29783
# lines: 599000, gameVec sz: 29833
# lines: 600000, gameVec sz: 29884
# lines: 601000, gameVec sz: 29934
# lines: 602000, gameVec sz: 29984
# lines: 603000, gameVec sz: 30035
# lines: 604000, gameVec sz: 30084
# lines: 605000, gameVec sz: 30135
# lines: 606000, gameVec sz: 30185
# lines: 607000, gameVec sz: 30238
# lines: 608000, gameVec sz: 30291
# lines: 609000, gameVec sz: 30341
# lines: 610000, gameVec sz: 30391
# lines: 611000, gameVec sz: 30440
# lines: 612000, gameVec sz: 30487
# lines: 613000, gameVec sz: 30538
# lines: 614000, gameVec sz: 30588
# lines: 615000, gameVec sz: 30639
# lines: 616000, gameVec sz: 30688
# lines: 617000, gameVec sz: 30738
# lines: 618000, gameVec sz: 30785
# lines: 619000, gameVec sz: 30833
# lines: 620000, gameVec sz: 30881
# lines: 621000, gameVec sz: 30931
# lines: 622000, gameVec sz: 30979
# lines: 623000, gameVec sz: 31031
# lines: 624000, gameVec sz: 31080
# lines: 625000, gameVec sz: 31131
# lines: 626000, gameVec sz: 31182
# lines: 627000, gameVec sz: 31232
# lines: 628000, gameVec sz: 31282
# lines: 629000, gameVec sz: 31333
# lines: 630000, gameVec sz: 31382
# lines: 631000, gameVec sz: 31431
# lines: 632000, gameVec sz: 31479
# lines: 633000, gameVec sz: 31531
# lines: 634000, gameVec sz: 31581
# lines: 635000, gameVec sz: 31633
# lines: 636000, gameVec sz: 31684
# lines: 637000, gameVec sz: 31735
# lines: 638000, gameVec sz: 31783
# lines: 639000, gameVec sz: 31834
# lines: 640000, gameVec sz: 31885
# lines: 641000, gameVec sz: 31935
# lines: 642000, gameVec sz: 31985
# lines: 643000, gameVec sz: 32035
# lines: 644000, gameVec sz: 32084
# lines: 645000, gameVec sz: 32134
# lines: 646000, gameVec sz: 32184
# lines: 647000, gameVec sz: 32234
# lines: 648000, gameVec sz: 32283
# lines: 649000, gameVec sz: 32333
# lines: 650000, gameVec sz: 32383
# lines: 651000, gameVec sz: 32433
# lines: 652000, gameVec sz: 32481
# lines: 653000, gameVec sz: 32531
# lines: 654000, gameVec sz: 32580
# lines: 655000, gameVec sz: 32629
# lines: 656000, gameVec sz: 32680
# lines: 657000, gameVec sz: 32731
# lines: 658000, gameVec sz: 32781
# lines: 659000, gameVec sz: 32831
# lines: 660000, gameVec sz: 32880
# lines: 661000, gameVec sz: 32932
# lines: 662000, gameVec sz: 32982
# lines: 663000, gameVec sz: 33032
# lines: 664000, gameVec sz: 33082
# lines: 665000, gameVec sz: 33132
# lines: 666000, gameVec sz: 33181
# lines: 667000, gameVec sz: 33231
# lines: 668000, gameVec sz: 33280
# lines: 669000, gameVec sz: 33327
# lines: 670000, gameVec sz: 33377
# lines: 671000, gameVec sz: 33426
# lines: 672000, gameVec sz: 33476
# lines: 673000, gameVec sz: 33527
# lines: 674000, gameVec sz: 33579
# lines: 675000, gameVec sz: 33630
# lines: 676000, gameVec sz: 33680
# lines: 677000, gameVec sz: 33729
# lines: 678000, gameVec sz: 33780
# lines: 679000, gameVec sz: 33829
# lines: 680000, gameVec sz: 33880
# lines: 681000, gameVec sz: 33929
# lines: 682000, gameVec sz: 33979
# lines: 683000, gameVec sz: 34029
# lines: 684000, gameVec sz: 34077
# lines: 685000, gameVec sz: 34126
# lines: 686000, gameVec sz: 34174
# lines: 687000, gameVec sz: 34221
# lines: 688000, gameVec sz: 34268
# lines: 689000, gameVec sz: 34316
# lines: 690000, gameVec sz: 34362
# lines: 691000, gameVec sz: 34411
# lines: 692000, gameVec sz: 34459
# lines: 693000, gameVec sz: 34507
# lines: 694000, gameVec sz: 34557
# lines: 695000, gameVec sz: 34608
# lines: 696000, gameVec sz: 34656
# lines: 697000, gameVec sz: 34705
# lines: 698000, gameVec sz: 34753
# lines: 699000, gameVec sz: 34803
# lines: 700000, gameVec sz: 34852
# lines: 701000, gameVec sz: 34901
# lines: 702000, gameVec sz: 34949
# lines: 703000, gameVec sz: 34999
# lines: 704000, gameVec sz: 35050
# lines: 705000, gameVec sz: 35101
# lines: 706000, gameVec sz: 35151
# lines: 707000, gameVec sz: 35201
# lines: 708000, gameVec sz: 35252
# lines: 709000, gameVec sz: 35302
# lines: 710000, gameVec sz: 35352
# lines: 711000, gameVec sz: 35402
# lines: 712000, gameVec sz: 35451
# lines: 713000, gameVec sz: 35502
# lines: 714000, gameVec sz: 35555
# lines: 715000, gameVec sz: 35604
# lines: 716000, gameVec sz: 35654
# lines: 717000, gameVec sz: 35704
# lines: 718000, gameVec sz: 35754
# lines: 719000, gameVec sz: 35807
# lines: 720000, gameVec sz: 35857
# lines: 721000, gameVec sz: 35906
# lines: 722000, gameVec sz: 35957
# lines: 723000, gameVec sz: 36009
# lines: 724000, gameVec sz: 36059
# lines: 725000, gameVec sz: 36109
# lines: 726000, gameVec sz: 36160
# lines: 727000, gameVec sz: 36210
# lines: 728000, gameVec sz: 36260
# lines: 729000, gameVec sz: 36311
# lines: 730000, gameVec sz: 36361
# lines: 731000, gameVec sz: 36408
# lines: 732000, gameVec sz: 36458
# lines: 733000, gameVec sz: 36509
# lines: 734000, gameVec sz: 36559
# lines: 735000, gameVec sz: 36609
# lines: 736000, gameVec sz: 36660
# lines: 737000, gameVec sz: 36710
# lines: 738000, gameVec sz: 36759
# lines: 739000, gameVec sz: 36810
# lines: 740000, gameVec sz: 36859
[2019/06/22 01:29:01]
# lines: 741000, gameVec sz: 36909
# lines: 742000, gameVec sz: 36958
# lines: 743000, gameVec sz: 37006
# lines: 744000, gameVec sz: 37057
# lines: 745000, gameVec sz: 37105
# lines: 746000, gameVec sz: 37155
# lines: 747000, gameVec sz: 37205
# lines: 748000, gameVec sz: 37255
# lines: 749000, gameVec sz: 37306
# lines: 750000, gameVec sz: 37358
# lines: 751000, gameVec sz: 37408
# lines: 752000, gameVec sz: 37460
# lines: 753000, gameVec sz: 37512
# lines: 754000, gameVec sz: 37562
# lines: 755000, gameVec sz: 37612
# lines: 756000, gameVec sz: 37664
# lines: 757000, gameVec sz: 37714
# lines: 758000, gameVec sz: 37763
# lines: 759000, gameVec sz: 37813
# lines: 760000, gameVec sz: 37862
# lines: 761000, gameVec sz: 37913
# lines: 762000, gameVec sz: 37964
# lines: 763000, gameVec sz: 38014
# lines: 764000, gameVec sz: 38064
# lines: 765000, gameVec sz: 38113
# lines: 766000, gameVec sz: 38163
# lines: 767000, gameVec sz: 38213
# lines: 768000, gameVec sz: 38262
# lines: 769000, gameVec sz: 38311
# lines: 770000, gameVec sz: 38361
# lines: 771000, gameVec sz: 38410
# lines: 772000, gameVec sz: 38460
# lines: 773000, gameVec sz: 38509
# lines: 774000, gameVec sz: 38558
# lines: 775000, gameVec sz: 38607
# lines: 776000, gameVec sz: 38659
# lines: 777000, gameVec sz: 38706
# lines: 778000, gameVec sz: 38756
# lines: 779000, gameVec sz: 38805
# lines: 780000, gameVec sz: 38853
# lines: 781000, gameVec sz: 38901
# lines: 782000, gameVec sz: 38950
# lines: 783000, gameVec sz: 39000
# lines: 784000, gameVec sz: 39051
# lines: 785000, gameVec sz: 39100
# lines: 786000, gameVec sz: 39150
# lines: 787000, gameVec sz: 39201
# lines: 788000, gameVec sz: 39251
# lines: 789000, gameVec sz: 39301
# lines: 790000, gameVec sz: 39351
# lines: 791000, gameVec sz: 39401
# lines: 792000, gameVec sz: 39452
# lines: 793000, gameVec sz: 39502
# lines: 794000, gameVec sz: 39552
# lines: 795000, gameVec sz: 39600
# lines: 796000, gameVec sz: 39649
# lines: 797000, gameVec sz: 39700
# lines: 798000, gameVec sz: 39749
# lines: 799000, gameVec sz: 39798
# lines: 800000, gameVec sz: 39849
# lines: 801000, gameVec sz: 39898
# lines: 802000, gameVec sz: 39947
# lines: 803000, gameVec sz: 39997
# lines: 804000, gameVec sz: 40046
# lines: 805000, gameVec sz: 40095
# lines: 806000, gameVec sz: 40142
# lines: 807000, gameVec sz: 40192
# lines: 808000, gameVec sz: 40241
# lines: 809000, gameVec sz: 40290
# lines: 810000, gameVec sz: 40342
# lines: 811000, gameVec sz: 40393
# lines: 812000, gameVec sz: 40444
# lines: 813000, gameVec sz: 40493
# lines: 814000, gameVec sz: 40544
# lines: 815000, gameVec sz: 40594
# lines: 816000, gameVec sz: 40643
# lines: 817000, gameVec sz: 40693
# lines: 818000, gameVec sz: 40745
# lines: 819000, gameVec sz: 40795
# lines: 820000, gameVec sz: 40844
# lines: 821000, gameVec sz: 40893
# lines: 822000, gameVec sz: 40942
# lines: 823000, gameVec sz: 40992
# lines: 824000, gameVec sz: 41042
# lines: 825000, gameVec sz: 41090
# lines: 826000, gameVec sz: 41139
# lines: 827000, gameVec sz: 41192
# lines: 828000, gameVec sz: 41242
# lines: 829000, gameVec sz: 41292
# lines: 830000, gameVec sz: 41344
# lines: 831000, gameVec sz: 41394
# lines: 832000, gameVec sz: 41445
# lines: 833000, gameVec sz: 41493
# lines: 834000, gameVec sz: 41544
# lines: 835000, gameVec sz: 41594
# lines: 836000, gameVec sz: 41643
# lines: 837000, gameVec sz: 41694
# lines: 838000, gameVec sz: 41743
# lines: 839000, gameVec sz: 41793
# lines: 840000, gameVec sz: 41844
# lines: 841000, gameVec sz: 41894
# lines: 842000, gameVec sz: 41945
# lines: 843000, gameVec sz: 41993
# lines: 844000, gameVec sz: 42043
# lines: 845000, gameVec sz: 42093
# lines: 846000, gameVec sz: 42144
# lines: 847000, gameVec sz: 42194
# lines: 848000, gameVec sz: 42243
# lines: 849000, gameVec sz: 42292
# lines: 850000, gameVec sz: 42340
# lines: 851000, gameVec sz: 42387
# lines: 852000, gameVec sz: 42436
# lines: 853000, gameVec sz: 42486
# lines: 854000, gameVec sz: 42534
# lines: 855000, gameVec sz: 42585
# lines: 856000, gameVec sz: 42636
# lines: 857000, gameVec sz: 42687
# lines: 858000, gameVec sz: 42738
# lines: 859000, gameVec sz: 42788
# lines: 860000, gameVec sz: 42838
# lines: 861000, gameVec sz: 42887
# lines: 862000, gameVec sz: 42939
# lines: 863000, gameVec sz: 42989
# lines: 864000, gameVec sz: 43040
# lines: 865000, gameVec sz: 43090
# lines: 866000, gameVec sz: 43140
# lines: 867000, gameVec sz: 43190
# lines: 868000, gameVec sz: 43241
# lines: 869000, gameVec sz: 43290
# lines: 870000, gameVec sz: 43340
# lines: 871000, gameVec sz: 43391
# lines: 872000, gameVec sz: 43441
# lines: 873000, gameVec sz: 43491
# lines: 874000, gameVec sz: 43540
# lines: 875000, gameVec sz: 43590
# lines: 876000, gameVec sz: 43641
# lines: 877000, gameVec sz: 43692
# lines: 878000, gameVec sz: 43741
# lines: 879000, gameVec sz: 43789
# lines: 880000, gameVec sz: 43840
# lines: 881000, gameVec sz: 43890
# lines: 882000, gameVec sz: 43941
# lines: 883000, gameVec sz: 43990
# lines: 884000, gameVec sz: 44041
# lines: 885000, gameVec sz: 44093
# lines: 886000, gameVec sz: 44144
# lines: 887000, gameVec sz: 44197
# lines: 888000, gameVec sz: 44251
# lines: 889000, gameVec sz: 44302
# lines: 890000, gameVec sz: 44357
# lines: 891000, gameVec sz: 44410
# lines: 892000, gameVec sz: 44463
# lines: 893000, gameVec sz: 44513
# lines: 894000, gameVec sz: 44564
# lines: 895000, gameVec sz: 44613
# lines: 896000, gameVec sz: 44663
# lines: 897000, gameVec sz: 44714
# lines: 898000, gameVec sz: 44765
# lines: 899000, gameVec sz: 44816
# lines: 900000, gameVec sz: 44865
# lines: 901000, gameVec sz: 44916
# lines: 902000, gameVec sz: 44966
# lines: 903000, gameVec sz: 45015
# lines: 904000, gameVec sz: 45066
# lines: 905000, gameVec sz: 45115
# lines: 906000, gameVec sz: 45164
# lines: 907000, gameVec sz: 45215
# lines: 908000, gameVec sz: 45263
# lines: 909000, gameVec sz: 45312
# lines: 910000, gameVec sz: 45362
# lines: 911000, gameVec sz: 45412
# lines: 912000, gameVec sz: 45462
# lines: 913000, gameVec sz: 45510
# lines: 914000, gameVec sz: 45560
# lines: 915000, gameVec sz: 45609
# lines: 916000, gameVec sz: 45661
# lines: 917000, gameVec sz: 45711
# lines: 918000, gameVec sz: 45762
# lines: 919000, gameVec sz: 45812
# lines: 920000, gameVec sz: 45863
# lines: 921000, gameVec sz: 45913
# lines: 922000, gameVec sz: 45964
# lines: 923000, gameVec sz: 46015
# lines: 924000, gameVec sz: 46064
# lines: 925000, gameVec sz: 46114
# lines: 926000, gameVec sz: 46163
# lines: 927000, gameVec sz: 46214
# lines: 928000, gameVec sz: 46263
# lines: 929000, gameVec sz: 46314
# lines: 930000, gameVec sz: 46364
# lines: 931000, gameVec sz: 46415
# lines: 932000, gameVec sz: 46464
# lines: 933000, gameVec sz: 46515
# lines: 934000, gameVec sz: 46565
# lines: 935000, gameVec sz: 46615
# lines: 936000, gameVec sz: 46668
# lines: 937000, gameVec sz: 46720
# lines: 938000, gameVec sz: 46771
# lines: 939000, gameVec sz: 46818
# lines: 940000, gameVec sz: 46866
# lines: 941000, gameVec sz: 46914
# lines: 942000, gameVec sz: 46963
# lines: 943000, gameVec sz: 47011
# lines: 944000, gameVec sz: 47060
# lines: 945000, gameVec sz: 47108
# lines: 946000, gameVec sz: 47156
# lines: 947000, gameVec sz: 47205
# lines: 948000, gameVec sz: 47255
# lines: 949000, gameVec sz: 47306
# lines: 950000, gameVec sz: 47357
# lines: 951000, gameVec sz: 47408
# lines: 952000, gameVec sz: 47459
# lines: 953000, gameVec sz: 47508
# lines: 954000, gameVec sz: 47558
# lines: 955000, gameVec sz: 47609
# lines: 956000, gameVec sz: 47659
# lines: 957000, gameVec sz: 47708
# lines: 958000, gameVec sz: 47758
# lines: 959000, gameVec sz: 47809
# lines: 960000, gameVec sz: 47858
# lines: 961000, gameVec sz: 47908
# lines: 962000, gameVec sz: 47959
# lines: 963000, gameVec sz: 48008
# lines: 964000, gameVec sz: 48057
# lines: 965000, gameVec sz: 48107
# lines: 966000, gameVec sz: 48157
# lines: 967000, gameVec sz: 48208
# lines: 968000, gameVec sz: 48255
# lines: 969000, gameVec sz: 48305
# lines: 970000, gameVec sz: 48353
# lines: 971000, gameVec sz: 48405
# lines: 972000, gameVec sz: 48456
# lines: 973000, gameVec sz: 48506
# lines: 974000, gameVec sz: 48557
# lines: 975000, gameVec sz: 48606
# lines: 976000, gameVec sz: 48656
# lines: 977000, gameVec sz: 48705
# lines: 978000, gameVec sz: 48755
# lines: 979000, gameVec sz: 48806
# lines: 980000, gameVec sz: 48855
# lines: 981000, gameVec sz: 48905
# lines: 982000, gameVec sz: 48953
# lines: 983000, gameVec sz: 49005
# lines: 984000, gameVec sz: 49056
# lines: 985000, gameVec sz: 49107
# lines: 986000, gameVec sz: 49156
# lines: 987000, gameVec sz: 49208
# lines: 988000, gameVec sz: 49257
# lines: 989000, gameVec sz: 49308
# lines: 990000, gameVec sz: 49357
# lines: 991000, gameVec sz: 49407
[2019/06/22 01:29:02]
# lines: 992000, gameVec sz: 49457
# lines: 993000, gameVec sz: 49506
# lines: 994000, gameVec sz: 49557
# lines: 995000, gameVec sz: 49606
# lines: 996000, gameVec sz: 49657
# lines: 997000, gameVec sz: 49707
# lines: 998000, gameVec sz: 49757
# lines: 999000, gameVec sz: 49808
# lines: 1000000, gameVec sz: 49858
# lines: 1001000, gameVec sz: 49908
# lines: 1002000, gameVec sz: 49957
# lines: 1003000, gameVec sz: 50007
# lines: 1004000, gameVec sz: 50058
# lines: 1005000, gameVec sz: 50107
# lines: 1006000, gameVec sz: 50155
# lines: 1007000, gameVec sz: 50207
# lines: 1008000, gameVec sz: 50257
# lines: 1009000, gameVec sz: 50306
# lines: 1010000, gameVec sz: 50357
# lines: 1011000, gameVec sz: 50407
# lines: 1012000, gameVec sz: 50460
# lines: 1013000, gameVec sz: 50513
# lines: 1014000, gameVec sz: 50563
# lines: 1015000, gameVec sz: 50615
# lines: 1016000, gameVec sz: 50664
# lines: 1017000, gameVec sz: 50716
# lines: 1018000, gameVec sz: 50766
# lines: 1019000, gameVec sz: 50817
# lines: 1020000, gameVec sz: 50868
# lines: 1021000, gameVec sz: 50919
# lines: 1022000, gameVec sz: 50970
# lines: 1023000, gameVec sz: 51021
# lines: 1024000, gameVec sz: 51070
# lines: 1025000, gameVec sz: 51119
# lines: 1026000, gameVec sz: 51167
# lines: 1027000, gameVec sz: 51213
# lines: 1028000, gameVec sz: 51263
# lines: 1029000, gameVec sz: 51312
# lines: 1030000, gameVec sz: 51362
# lines: 1031000, gameVec sz: 51414
# lines: 1032000, gameVec sz: 51465
# lines: 1033000, gameVec sz: 51516
# lines: 1034000, gameVec sz: 51566
# lines: 1035000, gameVec sz: 51616
# lines: 1036000, gameVec sz: 51666
# lines: 1037000, gameVec sz: 51717
# lines: 1038000, gameVec sz: 51767
# lines: 1039000, gameVec sz: 51816
# lines: 1040000, gameVec sz: 51865
# lines: 1041000, gameVec sz: 51913
# lines: 1042000, gameVec sz: 51964
# lines: 1043000, gameVec sz: 52017
# lines: 1044000, gameVec sz: 52069
# lines: 1045000, gameVec sz: 52120
# lines: 1046000, gameVec sz: 52171
# lines: 1047000, gameVec sz: 52222
# lines: 1048000, gameVec sz: 52272
# lines: 1049000, gameVec sz: 52323
# lines: 1050000, gameVec sz: 52375
# lines: 1051000, gameVec sz: 52424
# lines: 1052000, gameVec sz: 52474
# lines: 1053000, gameVec sz: 52525
# lines: 1054000, gameVec sz: 52575
# lines: 1055000, gameVec sz: 52627
# lines: 1056000, gameVec sz: 52677
# lines: 1057000, gameVec sz: 52727
# lines: 1058000, gameVec sz: 52775
# lines: 1059000, gameVec sz: 52825
# lines: 1060000, gameVec sz: 52875
# lines: 1061000, gameVec sz: 52926
# lines: 1062000, gameVec sz: 52977
# lines: 1063000, gameVec sz: 53027
# lines: 1064000, gameVec sz: 53077
# lines: 1065000, gameVec sz: 53126
# lines: 1066000, gameVec sz: 53179
# lines: 1067000, gameVec sz: 53231
# lines: 1068000, gameVec sz: 53283
# lines: 1069000, gameVec sz: 53336
# lines: 1070000, gameVec sz: 53386
# lines: 1071000, gameVec sz: 53437
# lines: 1072000, gameVec sz: 53487
# lines: 1073000, gameVec sz: 53540
# lines: 1074000, gameVec sz: 53589
# lines: 1075000, gameVec sz: 53640
# lines: 1076000, gameVec sz: 53691
# lines: 1077000, gameVec sz: 53744
# lines: 1078000, gameVec sz: 53795
# lines: 1079000, gameVec sz: 53846
# lines: 1080000, gameVec sz: 53894
# lines: 1081000, gameVec sz: 53944
# lines: 1082000, gameVec sz: 53995
# lines: 1083000, gameVec sz: 54045
# lines: 1084000, gameVec sz: 54097
# lines: 1085000, gameVec sz: 54146
# lines: 1086000, gameVec sz: 54196
# lines: 1087000, gameVec sz: 54246
# lines: 1088000, gameVec sz: 54296
# lines: 1089000, gameVec sz: 54346
# lines: 1090000, gameVec sz: 54396
# lines: 1091000, gameVec sz: 54445
# lines: 1092000, gameVec sz: 54494
# lines: 1093000, gameVec sz: 54544
# lines: 1094000, gameVec sz: 54595
# lines: 1095000, gameVec sz: 54645
# lines: 1096000, gameVec sz: 54696
# lines: 1097000, gameVec sz: 54746
# lines: 1098000, gameVec sz: 54793
# lines: 1099000, gameVec sz: 54845
# lines: 1100000, gameVec sz: 54895
# lines: 1101000, gameVec sz: 54947
# lines: 1102000, gameVec sz: 54996
# lines: 1103000, gameVec sz: 55047
# lines: 1104000, gameVec sz: 55098
# lines: 1105000, gameVec sz: 55149
# lines: 1106000, gameVec sz: 55199
# lines: 1107000, gameVec sz: 55250
# lines: 1108000, gameVec sz: 55299
# lines: 1109000, gameVec sz: 55349
# lines: 1110000, gameVec sz: 55400
# lines: 1111000, gameVec sz: 55450
# lines: 1112000, gameVec sz: 55501
# lines: 1113000, gameVec sz: 55550
# lines: 1114000, gameVec sz: 55601
# lines: 1115000, gameVec sz: 55651
# lines: 1116000, gameVec sz: 55701
# lines: 1117000, gameVec sz: 55751
# lines: 1118000, gameVec sz: 55799
# lines: 1119000, gameVec sz: 55850
# lines: 1120000, gameVec sz: 55900
# lines: 1121000, gameVec sz: 55952
# lines: 1122000, gameVec sz: 56003
# lines: 1123000, gameVec sz: 56054
# lines: 1124000, gameVec sz: 56105
# lines: 1125000, gameVec sz: 56156
# lines: 1126000, gameVec sz: 56204
# lines: 1127000, gameVec sz: 56253
# lines: 1128000, gameVec sz: 56300
# lines: 1129000, gameVec sz: 56350
# lines: 1130000, gameVec sz: 56400
# lines: 1131000, gameVec sz: 56449
# lines: 1132000, gameVec sz: 56499
# lines: 1133000, gameVec sz: 56550
# lines: 1134000, gameVec sz: 56601
# lines: 1135000, gameVec sz: 56653
# lines: 1136000, gameVec sz: 56704
# lines: 1137000, gameVec sz: 56756
# lines: 1138000, gameVec sz: 56805
# lines: 1139000, gameVec sz: 56853
# lines: 1140000, gameVec sz: 56903
# lines: 1141000, gameVec sz: 56954
# lines: 1142000, gameVec sz: 57003
# lines: 1143000, gameVec sz: 57053
# lines: 1144000, gameVec sz: 57103
# lines: 1145000, gameVec sz: 57153
# lines: 1146000, gameVec sz: 57203
# lines: 1147000, gameVec sz: 57253
# lines: 1148000, gameVec sz: 57302
# lines: 1149000, gameVec sz: 57352
# lines: 1150000, gameVec sz: 57400
# lines: 1151000, gameVec sz: 57450
# lines: 1152000, gameVec sz: 57500
# lines: 1153000, gameVec sz: 57551
# lines: 1154000, gameVec sz: 57600
# lines: 1155000, gameVec sz: 57650
# lines: 1156000, gameVec sz: 57700
# lines: 1157000, gameVec sz: 57750
# lines: 1158000, gameVec sz: 57800
# lines: 1159000, gameVec sz: 57851
# lines: 1160000, gameVec sz: 57902
# lines: 1161000, gameVec sz: 57953
# lines: 1162000, gameVec sz: 58004
# lines: 1163000, gameVec sz: 58056
# lines: 1164000, gameVec sz: 58106
# lines: 1165000, gameVec sz: 58158
# lines: 1166000, gameVec sz: 58208
# lines: 1167000, gameVec sz: 58259
# lines: 1168000, gameVec sz: 58308
# lines: 1169000, gameVec sz: 58361
# lines: 1170000, gameVec sz: 58412
# lines: 1171000, gameVec sz: 58462
# lines: 1172000, gameVec sz: 58513
# lines: 1173000, gameVec sz: 58563
# lines: 1174000, gameVec sz: 58614
# lines: 1175000, gameVec sz: 58663
# lines: 1176000, gameVec sz: 58714
# lines: 1177000, gameVec sz: 58762
# lines: 1178000, gameVec sz: 58812
# lines: 1179000, gameVec sz: 58863
# lines: 1180000, gameVec sz: 58914
# lines: 1181000, gameVec sz: 58964
# lines: 1182000, gameVec sz: 59014
# lines: 1183000, gameVec sz: 59064
# lines: 1184000, gameVec sz: 59113
# lines: 1185000, gameVec sz: 59165
# lines: 1186000, gameVec sz: 59214
# lines: 1187000, gameVec sz: 59266
# lines: 1188000, gameVec sz: 59317
# lines: 1189000, gameVec sz: 59367
# lines: 1190000, gameVec sz: 59418
# lines: 1191000, gameVec sz: 59468
# lines: 1192000, gameVec sz: 59517
# lines: 1193000, gameVec sz: 59567
# lines: 1194000, gameVec sz: 59619
# lines: 1195000, gameVec sz: 59667
# lines: 1196000, gameVec sz: 59720
# lines: 1197000, gameVec sz: 59771
# lines: 1198000, gameVec sz: 59819
# lines: 1199000, gameVec sz: 59868
# lines: 1200000, gameVec sz: 59917
# lines: 1201000, gameVec sz: 59966
# lines: 1202000, gameVec sz: 60015
# lines: 1203000, gameVec sz: 60063
# lines: 1204000, gameVec sz: 60113
# lines: 1205000, gameVec sz: 60165
# lines: 1206000, gameVec sz: 60216
# lines: 1207000, gameVec sz: 60266
# lines: 1208000, gameVec sz: 60315
# lines: 1209000, gameVec sz: 60367
# lines: 1210000, gameVec sz: 60418
# lines: 1211000, gameVec sz: 60469
# lines: 1212000, gameVec sz: 60520
# lines: 1213000, gameVec sz: 60570
# lines: 1214000, gameVec sz: 60619
# lines: 1215000, gameVec sz: 60669
# lines: 1216000, gameVec sz: 60720
# lines: 1217000, gameVec sz: 60770
# lines: 1218000, gameVec sz: 60821
# lines: 1219000, gameVec sz: 60873
# lines: 1220000, gameVec sz: 60924
# lines: 1221000, gameVec sz: 60975
# lines: 1222000, gameVec sz: 61024
# lines: 1223000, gameVec sz: 61075
# lines: 1224000, gameVec sz: 61125
# lines: 1225000, gameVec sz: 61173
# lines: 1226000, gameVec sz: 61225
# lines: 1227000, gameVec sz: 61276
# lines: 1228000, gameVec sz: 61327
# lines: 1229000, gameVec sz: 61376
# lines: 1230000, gameVec sz: 61427
# lines: 1231000, gameVec sz: 61478
# lines: 1232000, gameVec sz: 61529
# lines: 1233000, gameVec sz: 61578
# lines: 1234000, gameVec sz: 61628
# lines: 1235000, gameVec sz: 61679
# lines: 1236000, gameVec sz: 61730
# lines: 1237000, gameVec sz: 61782
# lines: 1238000, gameVec sz: 61834
# lines: 1239000, gameVec sz: 61886
# lines: 1240000, gameVec sz: 61939
# lines: 1241000, gameVec sz: 61992
# lines: 1242000, gameVec sz: 62046
# lines: 1243000, gameVec sz: 62098
# lines: 1244000, gameVec sz: 62148
# lines: 1245000, gameVec sz: 62200
# lines: 1246000, gameVec sz: 62251
[2019/06/22 01:29:03]
# lines: 1247000, gameVec sz: 62303
# lines: 1248000, gameVec sz: 62354
# lines: 1249000, gameVec sz: 62403
# lines: 1250000, gameVec sz: 62452
# lines: 1251000, gameVec sz: 62501
# lines: 1252000, gameVec sz: 62550
# lines: 1253000, gameVec sz: 62600
# lines: 1254000, gameVec sz: 62649
# lines: 1255000, gameVec sz: 62698
# lines: 1256000, gameVec sz: 62748
# lines: 1257000, gameVec sz: 62798
# lines: 1258000, gameVec sz: 62848
# lines: 1259000, gameVec sz: 62899
# lines: 1260000, gameVec sz: 62950
# lines: 1261000, gameVec sz: 63003
# lines: 1262000, gameVec sz: 63052
# lines: 1263000, gameVec sz: 63104
# lines: 1264000, gameVec sz: 63154
# lines: 1265000, gameVec sz: 63205
# lines: 1266000, gameVec sz: 63255
# lines: 1267000, gameVec sz: 63306
# lines: 1268000, gameVec sz: 63357
# lines: 1269000, gameVec sz: 63409
# lines: 1270000, gameVec sz: 63460
# lines: 1271000, gameVec sz: 63510
# lines: 1272000, gameVec sz: 63562
# lines: 1273000, gameVec sz: 63612
# lines: 1274000, gameVec sz: 63663
# lines: 1275000, gameVec sz: 63714
# lines: 1276000, gameVec sz: 63763
# lines: 1277000, gameVec sz: 63813
# lines: 1278000, gameVec sz: 63866
# lines: 1279000, gameVec sz: 63917
# lines: 1280000, gameVec sz: 63969
# lines: 1281000, gameVec sz: 64018
# lines: 1282000, gameVec sz: 64069
# lines: 1283000, gameVec sz: 64120
# lines: 1284000, gameVec sz: 64171
# lines: 1285000, gameVec sz: 64222
# lines: 1286000, gameVec sz: 64273
# lines: 1287000, gameVec sz: 64323
# lines: 1288000, gameVec sz: 64373
# lines: 1289000, gameVec sz: 64423
# lines: 1290000, gameVec sz: 64475
# lines: 1291000, gameVec sz: 64526
# lines: 1292000, gameVec sz: 64575
# lines: 1293000, gameVec sz: 64625
# lines: 1294000, gameVec sz: 64676
# lines: 1295000, gameVec sz: 64726
# lines: 1296000, gameVec sz: 64776
# lines: 1297000, gameVec sz: 64828
# lines: 1298000, gameVec sz: 64878
# lines: 1299000, gameVec sz: 64930
# lines: 1300000, gameVec sz: 64982
# lines: 1301000, gameVec sz: 65034
# lines: 1302000, gameVec sz: 65087
# lines: 1303000, gameVec sz: 65139
# lines: 1304000, gameVec sz: 65189
# lines: 1305000, gameVec sz: 65238
# lines: 1306000, gameVec sz: 65287
# lines: 1307000, gameVec sz: 65338
# lines: 1308000, gameVec sz: 65387
# lines: 1309000, gameVec sz: 65436
# lines: 1310000, gameVec sz: 65489
# lines: 1311000, gameVec sz: 65543
# lines: 1312000, gameVec sz: 65595
# lines: 1313000, gameVec sz: 65645
# lines: 1314000, gameVec sz: 65695
# lines: 1315000, gameVec sz: 65745
# lines: 1316000, gameVec sz: 65795
# lines: 1317000, gameVec sz: 65845
# lines: 1318000, gameVec sz: 65897
# lines: 1319000, gameVec sz: 65947
# lines: 1320000, gameVec sz: 66000
# lines: 1321000, gameVec sz: 66050
# lines: 1322000, gameVec sz: 66099
# lines: 1323000, gameVec sz: 66148
# lines: 1324000, gameVec sz: 66201
# lines: 1325000, gameVec sz: 66252
# lines: 1326000, gameVec sz: 66302
# lines: 1327000, gameVec sz: 66351
# lines: 1328000, gameVec sz: 66402
# lines: 1329000, gameVec sz: 66454
# lines: 1330000, gameVec sz: 66504
# lines: 1331000, gameVec sz: 66554
# lines: 1332000, gameVec sz: 66604
# lines: 1333000, gameVec sz: 66652
# lines: 1334000, gameVec sz: 66701
# lines: 1335000, gameVec sz: 66749
# lines: 1336000, gameVec sz: 66799
# lines: 1337000, gameVec sz: 66849
# lines: 1338000, gameVec sz: 66898
# lines: 1339000, gameVec sz: 66948
# lines: 1340000, gameVec sz: 67000
# lines: 1341000, gameVec sz: 67048
# lines: 1342000, gameVec sz: 67098
# lines: 1343000, gameVec sz: 67149
# lines: 1344000, gameVec sz: 67200
# lines: 1345000, gameVec sz: 67251
# lines: 1346000, gameVec sz: 67301
# lines: 1347000, gameVec sz: 67351
# lines: 1348000, gameVec sz: 67399
# lines: 1349000, gameVec sz: 67451
# lines: 1350000, gameVec sz: 67501
# lines: 1351000, gameVec sz: 67551
# lines: 1352000, gameVec sz: 67602
# lines: 1353000, gameVec sz: 67651
# lines: 1354000, gameVec sz: 67701
# lines: 1355000, gameVec sz: 67751
# lines: 1356000, gameVec sz: 67801
# lines: 1357000, gameVec sz: 67849
# lines: 1358000, gameVec sz: 67901
# lines: 1359000, gameVec sz: 67951
# lines: 1360000, gameVec sz: 68003
# lines: 1361000, gameVec sz: 68054
# lines: 1362000, gameVec sz: 68104
# lines: 1363000, gameVec sz: 68155
# lines: 1364000, gameVec sz: 68204
# lines: 1365000, gameVec sz: 68253
# lines: 1366000, gameVec sz: 68303
# lines: 1367000, gameVec sz: 68355
# lines: 1368000, gameVec sz: 68405
# lines: 1369000, gameVec sz: 68457
# lines: 1370000, gameVec sz: 68508
# lines: 1371000, gameVec sz: 68558
# lines: 1372000, gameVec sz: 68608
# lines: 1373000, gameVec sz: 68659
# lines: 1374000, gameVec sz: 68712
# lines: 1375000, gameVec sz: 68762
# lines: 1376000, gameVec sz: 68812
# lines: 1377000, gameVec sz: 68863
# lines: 1378000, gameVec sz: 68915
# lines: 1379000, gameVec sz: 68965
# lines: 1380000, gameVec sz: 69019
# lines: 1381000, gameVec sz: 69070
# lines: 1382000, gameVec sz: 69119
# lines: 1383000, gameVec sz: 69171
# lines: 1384000, gameVec sz: 69221
# lines: 1385000, gameVec sz: 69269
# lines: 1386000, gameVec sz: 69318
# lines: 1387000, gameVec sz: 69368
# lines: 1388000, gameVec sz: 69420
# lines: 1389000, gameVec sz: 69472
# lines: 1390000, gameVec sz: 69522
# lines: 1391000, gameVec sz: 69573
# lines: 1392000, gameVec sz: 69622
# lines: 1393000, gameVec sz: 69672
# lines: 1394000, gameVec sz: 69721
# lines: 1395000, gameVec sz: 69770
# lines: 1396000, gameVec sz: 69821
# lines: 1397000, gameVec sz: 69869
# lines: 1398000, gameVec sz: 69923
# lines: 1399000, gameVec sz: 69975
# lines: 1400000, gameVec sz: 70028
# lines: 1401000, gameVec sz: 70079
# lines: 1402000, gameVec sz: 70131
# lines: 1403000, gameVec sz: 70184
# lines: 1404000, gameVec sz: 70235
# lines: 1405000, gameVec sz: 70287
# lines: 1406000, gameVec sz: 70339
# lines: 1407000, gameVec sz: 70390
# lines: 1408000, gameVec sz: 70443
# lines: 1409000, gameVec sz: 70495
# lines: 1410000, gameVec sz: 70547
# lines: 1411000, gameVec sz: 70598
# lines: 1412000, gameVec sz: 70647
# lines: 1413000, gameVec sz: 70698
# lines: 1414000, gameVec sz: 70749
# lines: 1415000, gameVec sz: 70799
# lines: 1416000, gameVec sz: 70850
# lines: 1417000, gameVec sz: 70900
# lines: 1418000, gameVec sz: 70951
# lines: 1419000, gameVec sz: 71002
# lines: 1420000, gameVec sz: 71052
# lines: 1421000, gameVec sz: 71102
# lines: 1422000, gameVec sz: 71154
# lines: 1423000, gameVec sz: 71205
# lines: 1424000, gameVec sz: 71257
# lines: 1425000, gameVec sz: 71307
# lines: 1426000, gameVec sz: 71359
# lines: 1427000, gameVec sz: 71409
# lines: 1428000, gameVec sz: 71460
# lines: 1429000, gameVec sz: 71512
# lines: 1430000, gameVec sz: 71563
# lines: 1431000, gameVec sz: 71617
# lines: 1432000, gameVec sz: 71668
# lines: 1433000, gameVec sz: 71718
# lines: 1434000, gameVec sz: 71768
# lines: 1435000, gameVec sz: 71819
# lines: 1436000, gameVec sz: 71869
# lines: 1437000, gameVec sz: 71919
# lines: 1438000, gameVec sz: 71968
# lines: 1439000, gameVec sz: 72020
# lines: 1440000, gameVec sz: 72071
# lines: 1441000, gameVec sz: 72124
# lines: 1442000, gameVec sz: 72174
# lines: 1443000, gameVec sz: 72226
# lines: 1444000, gameVec sz: 72277
# lines: 1445000, gameVec sz: 72328
# lines: 1446000, gameVec sz: 72380
# lines: 1447000, gameVec sz: 72428
# lines: 1448000, gameVec sz: 72477
# lines: 1449000, gameVec sz: 72527
# lines: 1450000, gameVec sz: 72580
# lines: 1451000, gameVec sz: 72630
# lines: 1452000, gameVec sz: 72680
# lines: 1453000, gameVec sz: 72730
# lines: 1454000, gameVec sz: 72781
# lines: 1455000, gameVec sz: 72833
# lines: 1456000, gameVec sz: 72884
# lines: 1457000, gameVec sz: 72936
# lines: 1458000, gameVec sz: 72987
# lines: 1459000, gameVec sz: 73037
# lines: 1460000, gameVec sz: 73088
# lines: 1461000, gameVec sz: 73138
# lines: 1462000, gameVec sz: 73189
# lines: 1463000, gameVec sz: 73239
# lines: 1464000, gameVec sz: 73290
# lines: 1465000, gameVec sz: 73340
# lines: 1466000, gameVec sz: 73390
# lines: 1467000, gameVec sz: 73440
# lines: 1468000, gameVec sz: 73490
# lines: 1469000, gameVec sz: 73540
# lines: 1470000, gameVec sz: 73588
# lines: 1471000, gameVec sz: 73640
# lines: 1472000, gameVec sz: 73690
# lines: 1473000, gameVec sz: 73741
# lines: 1474000, gameVec sz: 73793
# lines: 1475000, gameVec sz: 73845
# lines: 1476000, gameVec sz: 73896
# lines: 1477000, gameVec sz: 73948
# lines: 1478000, gameVec sz: 73999
# lines: 1479000, gameVec sz: 74050
# lines: 1480000, gameVec sz: 74101
# lines: 1481000, gameVec sz: 74154
# lines: 1482000, gameVec sz: 74204
# lines: 1483000, gameVec sz: 74254
# lines: 1484000, gameVec sz: 74305
# lines: 1485000, gameVec sz: 74356
[2019/06/22 01:29:04]
# lines: 1486000, gameVec sz: 74407
# lines: 1487000, gameVec sz: 74458
# lines: 1488000, gameVec sz: 74509
# lines: 1489000, gameVec sz: 74558
# lines: 1490000, gameVec sz: 74609
# lines: 1491000, gameVec sz: 74659
# lines: 1492000, gameVec sz: 74710
# lines: 1493000, gameVec sz: 74761
# lines: 1494000, gameVec sz: 74810
# lines: 1495000, gameVec sz: 74861
# lines: 1496000, gameVec sz: 74911
# lines: 1497000, gameVec sz: 74962
# lines: 1498000, gameVec sz: 75013
# lines: 1499000, gameVec sz: 75062
# lines: 1500000, gameVec sz: 75113
# lines: 1501000, gameVec sz: 75164
# lines: 1502000, gameVec sz: 75214
# lines: 1503000, gameVec sz: 75265
# lines: 1504000, gameVec sz: 75316
# lines: 1505000, gameVec sz: 75367
# lines: 1506000, gameVec sz: 75415
# lines: 1507000, gameVec sz: 75464
# lines: 1508000, gameVec sz: 75515
# lines: 1509000, gameVec sz: 75565
# lines: 1510000, gameVec sz: 75615
# lines: 1511000, gameVec sz: 75665
# lines: 1512000, gameVec sz: 75715
# lines: 1513000, gameVec sz: 75764
# lines: 1514000, gameVec sz: 75815
# lines: 1515000, gameVec sz: 75867
# lines: 1516000, gameVec sz: 75918
# lines: 1517000, gameVec sz: 75969
# lines: 1518000, gameVec sz: 76019
# lines: 1519000, gameVec sz: 76069
# lines: 1520000, gameVec sz: 76118
# lines: 1521000, gameVec sz: 76169
# lines: 1522000, gameVec sz: 76218
# lines: 1523000, gameVec sz: 76267
# lines: 1524000, gameVec sz: 76318
# lines: 1525000, gameVec sz: 76368
# lines: 1526000, gameVec sz: 76417
# lines: 1527000, gameVec sz: 76469
# lines: 1528000, gameVec sz: 76520
# lines: 1529000, gameVec sz: 76569
# lines: 1530000, gameVec sz: 76620
# lines: 1531000, gameVec sz: 76669
# lines: 1532000, gameVec sz: 76720
# lines: 1533000, gameVec sz: 76770
# lines: 1534000, gameVec sz: 76821
# lines: 1535000, gameVec sz: 76870
# lines: 1536000, gameVec sz: 76921
# lines: 1537000, gameVec sz: 76971
# lines: 1538000, gameVec sz: 77023
# lines: 1539000, gameVec sz: 77072
# lines: 1540000, gameVec sz: 77122
# lines: 1541000, gameVec sz: 77174
# lines: 1542000, gameVec sz: 77226
# lines: 1543000, gameVec sz: 77276
# lines: 1544000, gameVec sz: 77327
# lines: 1545000, gameVec sz: 77379
# lines: 1546000, gameVec sz: 77428
# lines: 1547000, gameVec sz: 77477
# lines: 1548000, gameVec sz: 77528
# lines: 1549000, gameVec sz: 77578
# lines: 1550000, gameVec sz: 77630
# lines: 1551000, gameVec sz: 77679
# lines: 1552000, gameVec sz: 77730
# lines: 1553000, gameVec sz: 77779
# lines: 1554000, gameVec sz: 77829
# lines: 1555000, gameVec sz: 77880
# lines: 1556000, gameVec sz: 77932
# lines: 1557000, gameVec sz: 77985
# lines: 1558000, gameVec sz: 78034
# lines: 1559000, gameVec sz: 78084
# lines: 1560000, gameVec sz: 78134
# lines: 1561000, gameVec sz: 78186
# lines: 1562000, gameVec sz: 78236
# lines: 1563000, gameVec sz: 78288
# lines: 1564000, gameVec sz: 78340
# lines: 1565000, gameVec sz: 78391
# lines: 1566000, gameVec sz: 78440
# lines: 1567000, gameVec sz: 78490
# lines: 1568000, gameVec sz: 78540
# lines: 1569000, gameVec sz: 78592
# lines: 1570000, gameVec sz: 78646
# lines: 1571000, gameVec sz: 78697
# lines: 1572000, gameVec sz: 78749
# lines: 1573000, gameVec sz: 78799
# lines: 1574000, gameVec sz: 78850
# lines: 1575000, gameVec sz: 78900
# lines: 1576000, gameVec sz: 78953
# lines: 1577000, gameVec sz: 79003
# lines: 1578000, gameVec sz: 79055
# lines: 1579000, gameVec sz: 79106
# lines: 1580000, gameVec sz: 79157
# lines: 1581000, gameVec sz: 79205
# lines: 1582000, gameVec sz: 79255
# lines: 1583000, gameVec sz: 79306
# lines: 1584000, gameVec sz: 79357
# lines: 1585000, gameVec sz: 79409
# lines: 1586000, gameVec sz: 79459
# lines: 1587000, gameVec sz: 79511
# lines: 1588000, gameVec sz: 79562
# lines: 1589000, gameVec sz: 79614
# lines: 1590000, gameVec sz: 79666
# lines: 1591000, gameVec sz: 79718
# lines: 1592000, gameVec sz: 79767
# lines: 1593000, gameVec sz: 79817
# lines: 1594000, gameVec sz: 79869
# lines: 1595000, gameVec sz: 79921
# lines: 1596000, gameVec sz: 79970
# lines: 1597000, gameVec sz: 80022
# lines: 1598000, gameVec sz: 80071
# lines: 1599000, gameVec sz: 80122
# lines: 1600000, gameVec sz: 80172
# lines: 1601000, gameVec sz: 80223
# lines: 1602000, gameVec sz: 80274
# lines: 1603000, gameVec sz: 80325
# lines: 1604000, gameVec sz: 80378
# lines: 1605000, gameVec sz: 80427
# lines: 1606000, gameVec sz: 80478
# lines: 1607000, gameVec sz: 80529
# lines: 1608000, gameVec sz: 80579
# lines: 1609000, gameVec sz: 80632
# lines: 1610000, gameVec sz: 80683
# lines: 1611000, gameVec sz: 80733
# lines: 1612000, gameVec sz: 80784
# lines: 1613000, gameVec sz: 80836
# lines: 1614000, gameVec sz: 80888
# lines: 1615000, gameVec sz: 80935
# lines: 1616000, gameVec sz: 80985
# lines: 1617000, gameVec sz: 81033
# lines: 1618000, gameVec sz: 81083
# lines: 1619000, gameVec sz: 81131
# lines: 1620000, gameVec sz: 81181
# lines: 1621000, gameVec sz: 81231
# lines: 1622000, gameVec sz: 81282
# lines: 1623000, gameVec sz: 81330
# lines: 1624000, gameVec sz: 81380
# lines: 1625000, gameVec sz: 81431
# lines: 1626000, gameVec sz: 81482
# lines: 1627000, gameVec sz: 81532
# lines: 1628000, gameVec sz: 81582
# lines: 1629000, gameVec sz: 81633
# lines: 1630000, gameVec sz: 81685
# lines: 1631000, gameVec sz: 81738
# lines: 1632000, gameVec sz: 81790
# lines: 1633000, gameVec sz: 81841
# lines: 1634000, gameVec sz: 81889
# lines: 1635000, gameVec sz: 81939
# lines: 1636000, gameVec sz: 81989
# lines: 1637000, gameVec sz: 82043
# lines: 1638000, gameVec sz: 82093
# lines: 1639000, gameVec sz: 82145
# lines: 1640000, gameVec sz: 82196
# lines: 1641000, gameVec sz: 82249
# lines: 1642000, gameVec sz: 82301
# lines: 1643000, gameVec sz: 82354
# lines: 1644000, gameVec sz: 82404
# lines: 1645000, gameVec sz: 82456
# lines: 1646000, gameVec sz: 82510
# lines: 1647000, gameVec sz: 82563
# lines: 1648000, gameVec sz: 82615
# lines: 1649000, gameVec sz: 82666
# lines: 1650000, gameVec sz: 82716
# lines: 1651000, gameVec sz: 82767
# lines: 1652000, gameVec sz: 82818
# lines: 1653000, gameVec sz: 82869
# lines: 1654000, gameVec sz: 82920
# lines: 1655000, gameVec sz: 82972
# lines: 1656000, gameVec sz: 83021
# lines: 1657000, gameVec sz: 83072
# lines: 1658000, gameVec sz: 83121
# lines: 1659000, gameVec sz: 83173
# lines: 1660000, gameVec sz: 83224
# lines: 1661000, gameVec sz: 83277
# lines: 1662000, gameVec sz: 83329
# lines: 1663000, gameVec sz: 83381
# lines: 1664000, gameVec sz: 83432
# lines: 1665000, gameVec sz: 83482
# lines: 1666000, gameVec sz: 83536
# lines: 1667000, gameVec sz: 83587
# lines: 1668000, gameVec sz: 83638
# lines: 1669000, gameVec sz: 83691
# lines: 1670000, gameVec sz: 83742
# lines: 1671000, gameVec sz: 83794
# lines: 1672000, gameVec sz: 83845
# lines: 1673000, gameVec sz: 83896
# lines: 1674000, gameVec sz: 83947
# lines: 1675000, gameVec sz: 83998
# lines: 1676000, gameVec sz: 84049
# lines: 1677000, gameVec sz: 84099
# lines: 1678000, gameVec sz: 84149
# lines: 1679000, gameVec sz: 84198
# lines: 1680000, gameVec sz: 84249
# lines: 1681000, gameVec sz: 84298
# lines: 1682000, gameVec sz: 84348
# lines: 1683000, gameVec sz: 84399
# lines: 1684000, gameVec sz: 84450
# lines: 1685000, gameVec sz: 84503
# lines: 1686000, gameVec sz: 84554
# lines: 1687000, gameVec sz: 84607
# lines: 1688000, gameVec sz: 84659
# lines: 1689000, gameVec sz: 84712
# lines: 1690000, gameVec sz: 84762
# lines: 1691000, gameVec sz: 84812
# lines: 1692000, gameVec sz: 84864
# lines: 1693000, gameVec sz: 84914
# lines: 1694000, gameVec sz: 84965
# lines: 1695000, gameVec sz: 85014
# lines: 1696000, gameVec sz: 85066
# lines: 1697000, gameVec sz: 85116
# lines: 1698000, gameVec sz: 85165
# lines: 1699000, gameVec sz: 85219
# lines: 1700000, gameVec sz: 85272
# lines: 1701000, gameVec sz: 85325
# lines: 1702000, gameVec sz: 85374
# lines: 1703000, gameVec sz: 85425
# lines: 1704000, gameVec sz: 85480
# lines: 1705000, gameVec sz: 85531
# lines: 1706000, gameVec sz: 85583
# lines: 1707000, gameVec sz: 85632
# lines: 1708000, gameVec sz: 85685
# lines: 1709000, gameVec sz: 85735
# lines: 1710000, gameVec sz: 85787
# lines: 1711000, gameVec sz: 85840
# lines: 1712000, gameVec sz: 85891
# lines: 1713000, gameVec sz: 85942
# lines: 1714000, gameVec sz: 85993
# lines: 1715000, gameVec sz: 86045
# lines: 1716000, gameVec sz: 86097
# lines: 1717000, gameVec sz: 86147
# lines: 1718000, gameVec sz: 86199
# lines: 1719000, gameVec sz: 86250
# lines: 1720000, gameVec sz: 86300
# lines: 1721000, gameVec sz: 86351
# lines: 1722000, gameVec sz: 86400
# lines: 1723000, gameVec sz: 86451
# lines: 1724000, gameVec sz: 86503
# lines: 1725000, gameVec sz: 86553
# lines: 1726000, gameVec sz: 86604
# lines: 1727000, gameVec sz: 86655
# lines: 1728000, gameVec sz: 86705
# lines: 1729000, gameVec sz: 86757
# lines: 1730000, gameVec sz: 86808
# lines: 1731000, gameVec sz: 86860
# lines: 1732000, gameVec sz: 86911
# lines: 1733000, gameVec sz: 86963
# lines: 1734000, gameVec sz: 87013
# lines: 1735000, gameVec sz: 87064
# lines: 1736000, gameVec sz: 87114
# lines: 1737000, gameVec sz: 87164
# lines: 1738000, gameVec sz: 87212
# lines: 1739000, gameVec sz: 87262
# lines: 1740000, gameVec sz: 87313
# lines: 1741000, gameVec sz: 87365
# lines: 1742000, gameVec sz: 87416
# lines: 1743000, gameVec sz: 87469
# lines: 1744000, gameVec sz: 87520
# lines: 1745000, gameVec sz: 87572
# lines: 1746000, gameVec sz: 87623
# lines: 1747000, gameVec sz: 87674
[2019/06/22 01:29:05]
# lines: 1748000, gameVec sz: 87723
# lines: 1749000, gameVec sz: 87775
# lines: 1750000, gameVec sz: 87827
# lines: 1751000, gameVec sz: 87880
# lines: 1752000, gameVec sz: 87931
# lines: 1753000, gameVec sz: 87984
# lines: 1754000, gameVec sz: 88036
# lines: 1755000, gameVec sz: 88089
# lines: 1756000, gameVec sz: 88141
# lines: 1757000, gameVec sz: 88193
# lines: 1758000, gameVec sz: 88242
# lines: 1759000, gameVec sz: 88293
# lines: 1760000, gameVec sz: 88344
# lines: 1761000, gameVec sz: 88394
# lines: 1762000, gameVec sz: 88446
# lines: 1763000, gameVec sz: 88497
# lines: 1764000, gameVec sz: 88550
# lines: 1765000, gameVec sz: 88603
# lines: 1766000, gameVec sz: 88653
# lines: 1767000, gameVec sz: 88706
# lines: 1768000, gameVec sz: 88757
# lines: 1769000, gameVec sz: 88808
# lines: 1770000, gameVec sz: 88859
# lines: 1771000, gameVec sz: 88909
# lines: 1772000, gameVec sz: 88957
# lines: 1773000, gameVec sz: 89006
# lines: 1774000, gameVec sz: 89055
# lines: 1775000, gameVec sz: 89106
# lines: 1776000, gameVec sz: 89159
# lines: 1777000, gameVec sz: 89210
# lines: 1778000, gameVec sz: 89262
# lines: 1779000, gameVec sz: 89312
# lines: 1780000, gameVec sz: 89361
# lines: 1781000, gameVec sz: 89412
# lines: 1782000, gameVec sz: 89463
# lines: 1783000, gameVec sz: 89513
# lines: 1784000, gameVec sz: 89564
# lines: 1785000, gameVec sz: 89615
# lines: 1786000, gameVec sz: 89662
# lines: 1787000, gameVec sz: 89712
# lines: 1788000, gameVec sz: 89764
# lines: 1789000, gameVec sz: 89814
# lines: 1790000, gameVec sz: 89867
# lines: 1791000, gameVec sz: 89918
# lines: 1792000, gameVec sz: 89968
# lines: 1793000, gameVec sz: 90018
# lines: 1794000, gameVec sz: 90067
# lines: 1795000, gameVec sz: 90119
# lines: 1796000, gameVec sz: 90170
# lines: 1797000, gameVec sz: 90220
# lines: 1798000, gameVec sz: 90270
# lines: 1799000, gameVec sz: 90321
# lines: 1800000, gameVec sz: 90372
# lines: 1801000, gameVec sz: 90423
# lines: 1802000, gameVec sz: 90474
# lines: 1803000, gameVec sz: 90527
# lines: 1804000, gameVec sz: 90578
# lines: 1805000, gameVec sz: 90630
# lines: 1806000, gameVec sz: 90680
# lines: 1807000, gameVec sz: 90732
# lines: 1808000, gameVec sz: 90784
# lines: 1809000, gameVec sz: 90835
# lines: 1810000, gameVec sz: 90886
# lines: 1811000, gameVec sz: 90936
# lines: 1812000, gameVec sz: 90990
# lines: 1813000, gameVec sz: 91040
# lines: 1814000, gameVec sz: 91090
# lines: 1815000, gameVec sz: 91141
# lines: 1816000, gameVec sz: 91192
# lines: 1817000, gameVec sz: 91244
# lines: 1818000, gameVec sz: 91296
# lines: 1819000, gameVec sz: 91347
# lines: 1820000, gameVec sz: 91397
# lines: 1821000, gameVec sz: 91450
# lines: 1822000, gameVec sz: 91502
# lines: 1823000, gameVec sz: 91553
# lines: 1824000, gameVec sz: 91606
# lines: 1825000, gameVec sz: 91660
# lines: 1826000, gameVec sz: 91711
# lines: 1827000, gameVec sz: 91763
# lines: 1828000, gameVec sz: 91815
# lines: 1829000, gameVec sz: 91868
# lines: 1830000, gameVec sz: 91920
# lines: 1831000, gameVec sz: 91972
# lines: 1832000, gameVec sz: 92023
# lines: 1833000, gameVec sz: 92077
# lines: 1834000, gameVec sz: 92128
# lines: 1835000, gameVec sz: 92181
# lines: 1836000, gameVec sz: 92232
# lines: 1837000, gameVec sz: 92283
# lines: 1838000, gameVec sz: 92333
# lines: 1839000, gameVec sz: 92386
# lines: 1840000, gameVec sz: 92437
# lines: 1841000, gameVec sz: 92490
# lines: 1842000, gameVec sz: 92541
# lines: 1843000, gameVec sz: 92593
# lines: 1844000, gameVec sz: 92644
# lines: 1845000, gameVec sz: 92696
# lines: 1846000, gameVec sz: 92747
# lines: 1847000, gameVec sz: 92798
# lines: 1848000, gameVec sz: 92848
# lines: 1849000, gameVec sz: 92898
# lines: 1850000, gameVec sz: 92949
# lines: 1851000, gameVec sz: 92999
# lines: 1852000, gameVec sz: 93052
# lines: 1853000, gameVec sz: 93102
# lines: 1854000, gameVec sz: 93154
# lines: 1855000, gameVec sz: 93205
# lines: 1856000, gameVec sz: 93256
# lines: 1857000, gameVec sz: 93307
# lines: 1858000, gameVec sz: 93358
# lines: 1859000, gameVec sz: 93409
# lines: 1860000, gameVec sz: 93460
# lines: 1861000, gameVec sz: 93510
# lines: 1862000, gameVec sz: 93561
# lines: 1863000, gameVec sz: 93614
# lines: 1864000, gameVec sz: 93665
# lines: 1865000, gameVec sz: 93715
# lines: 1866000, gameVec sz: 93765
# lines: 1867000, gameVec sz: 93818
# lines: 1868000, gameVec sz: 93869
# lines: 1869000, gameVec sz: 93921
# lines: 1870000, gameVec sz: 93971
# lines: 1871000, gameVec sz: 94024
# lines: 1872000, gameVec sz: 94074
# lines: 1873000, gameVec sz: 94128
# lines: 1874000, gameVec sz: 94179
# lines: 1875000, gameVec sz: 94231
# lines: 1876000, gameVec sz: 94283
# lines: 1877000, gameVec sz: 94334
# lines: 1878000, gameVec sz: 94384
# lines: 1879000, gameVec sz: 94434
# lines: 1880000, gameVec sz: 94484
# lines: 1881000, gameVec sz: 94536
# lines: 1882000, gameVec sz: 94586
# lines: 1883000, gameVec sz: 94639
# lines: 1884000, gameVec sz: 94690
# lines: 1885000, gameVec sz: 94741
# lines: 1886000, gameVec sz: 94793
# lines: 1887000, gameVec sz: 94845
# lines: 1888000, gameVec sz: 94896
# lines: 1889000, gameVec sz: 94946
# lines: 1890000, gameVec sz: 94999
# lines: 1891000, gameVec sz: 95051
# lines: 1892000, gameVec sz: 95102
# lines: 1893000, gameVec sz: 95154
# lines: 1894000, gameVec sz: 95204
# lines: 1895000, gameVec sz: 95255
# lines: 1896000, gameVec sz: 95306
# lines: 1897000, gameVec sz: 95359
# lines: 1898000, gameVec sz: 95411
# lines: 1899000, gameVec sz: 95463
# lines: 1900000, gameVec sz: 95514
# lines: 1901000, gameVec sz: 95565
# lines: 1902000, gameVec sz: 95615
# lines: 1903000, gameVec sz: 95666
# lines: 1904000, gameVec sz: 95717
# lines: 1905000, gameVec sz: 95769
# lines: 1906000, gameVec sz: 95823
# lines: 1907000, gameVec sz: 95878
# lines: 1908000, gameVec sz: 95930
# lines: 1909000, gameVec sz: 95982
# lines: 1910000, gameVec sz: 96031
# lines: 1911000, gameVec sz: 96081
# lines: 1912000, gameVec sz: 96131
# lines: 1913000, gameVec sz: 96183
# lines: 1914000, gameVec sz: 96234
# lines: 1915000, gameVec sz: 96284
# lines: 1916000, gameVec sz: 96335
# lines: 1917000, gameVec sz: 96385
# lines: 1918000, gameVec sz: 96440
# lines: 1919000, gameVec sz: 96492
# lines: 1920000, gameVec sz: 96544
# lines: 1921000, gameVec sz: 96595
# lines: 1922000, gameVec sz: 96647
# lines: 1923000, gameVec sz: 96697
# lines: 1924000, gameVec sz: 96751
# lines: 1925000, gameVec sz: 96804
# lines: 1926000, gameVec sz: 96856
# lines: 1927000, gameVec sz: 96908
# lines: 1928000, gameVec sz: 96959
# lines: 1929000, gameVec sz: 97011
# lines: 1930000, gameVec sz: 97063
# lines: 1931000, gameVec sz: 97113
# lines: 1932000, gameVec sz: 97165
# lines: 1933000, gameVec sz: 97216
# lines: 1934000, gameVec sz: 97266
# lines: 1935000, gameVec sz: 97316
# lines: 1936000, gameVec sz: 97368
# lines: 1937000, gameVec sz: 97421
# lines: 1938000, gameVec sz: 97471
# lines: 1939000, gameVec sz: 97523
# lines: 1940000, gameVec sz: 97576
# lines: 1941000, gameVec sz: 97628
# lines: 1942000, gameVec sz: 97681
# lines: 1943000, gameVec sz: 97732
# lines: 1944000, gameVec sz: 97783
# lines: 1945000, gameVec sz: 97835
# lines: 1946000, gameVec sz: 97889
# lines: 1947000, gameVec sz: 97941
# lines: 1948000, gameVec sz: 97995
# lines: 1949000, gameVec sz: 98046
# lines: 1950000, gameVec sz: 98097
# lines: 1951000, gameVec sz: 98149
# lines: 1952000, gameVec sz: 98203
# lines: 1953000, gameVec sz: 98253
# lines: 1954000, gameVec sz: 98305
# lines: 1955000, gameVec sz: 98356
# lines: 1956000, gameVec sz: 98409
# lines: 1957000, gameVec sz: 98458
# lines: 1958000, gameVec sz: 98510
# lines: 1959000, gameVec sz: 98560
# lines: 1960000, gameVec sz: 98612
# lines: 1961000, gameVec sz: 98665
# lines: 1962000, gameVec sz: 98715
# lines: 1963000, gameVec sz: 98766
# lines: 1964000, gameVec sz: 98819
# lines: 1965000, gameVec sz: 98872
# lines: 1966000, gameVec sz: 98923
# lines: 1967000, gameVec sz: 98973
# lines: 1968000, gameVec sz: 99023
# lines: 1969000, gameVec sz: 99073
# lines: 1970000, gameVec sz: 99124
# lines: 1971000, gameVec sz: 99176
# lines: 1972000, gameVec sz: 99226
# lines: 1973000, gameVec sz: 99278
# lines: 1974000, gameVec sz: 99331
# lines: 1975000, gameVec sz: 99384
# lines: 1976000, gameVec sz: 99438
# lines: 1977000, gameVec sz: 99490
# lines: 1978000, gameVec sz: 99541
# lines: 1979000, gameVec sz: 99593
# lines: 1980000, gameVec sz: 99644
# lines: 1981000, gameVec sz: 99697
# lines: 1982000, gameVec sz: 99748
# lines: 1983000, gameVec sz: 99800
# lines: 1984000, gameVec sz: 99853
# lines: 1985000, gameVec sz: 99905
# lines: 1986000, gameVec sz: 99956
# lines: 1987000, gameVec sz: 100006
# lines: 1988000, gameVec sz: 100059
# lines: 1989000, gameVec sz: 100109
# lines: 1990000, gameVec sz: 100161
# lines: 1991000, gameVec sz: 100215
# lines: 1992000, gameVec sz: 100268
# lines: 1993000, gameVec sz: 100320
# lines: 1994000, gameVec sz: 100371
# lines: 1995000, gameVec sz: 100421
# lines: 1996000, gameVec sz: 100473
# lines: 1997000, gameVec sz: 100526
# lines: 1998000, gameVec sz: 100577
# lines: 1999000, gameVec sz: 100625
# lines: 2000000, gameVec sz: 100677
# lines: 2001000, gameVec sz: 100729
# lines: 2002000, gameVec sz: 100779
# lines: 2003000, gameVec sz: 100832
# lines: 2004000, gameVec sz: 100883
# lines: 2005000, gameVec sz: 100935
# lines: 2006000, gameVec sz: 100988
# lines: 2007000, gameVec sz: 101039
# lines: 2008000, gameVec sz: 101088
# lines: 2009000, gameVec sz: 101141
[2019/06/22 01:29:06]
# lines: 2010000, gameVec sz: 101194
# lines: 2011000, gameVec sz: 101245
# lines: 2012000, gameVec sz: 101297
# lines: 2013000, gameVec sz: 101349
# lines: 2014000, gameVec sz: 101401
# lines: 2015000, gameVec sz: 101452
# lines: 2016000, gameVec sz: 101504
# lines: 2017000, gameVec sz: 101555
# lines: 2018000, gameVec sz: 101606
# lines: 2019000, gameVec sz: 101655
# lines: 2020000, gameVec sz: 101708
# lines: 2021000, gameVec sz: 101761
# lines: 2022000, gameVec sz: 101812
# lines: 2023000, gameVec sz: 101862
# lines: 2024000, gameVec sz: 101914
# lines: 2025000, gameVec sz: 101964
# lines: 2026000, gameVec sz: 102015
# lines: 2027000, gameVec sz: 102068
# lines: 2028000, gameVec sz: 102121
# lines: 2029000, gameVec sz: 102173
# lines: 2030000, gameVec sz: 102227
# lines: 2031000, gameVec sz: 102281
# lines: 2032000, gameVec sz: 102335
# lines: 2033000, gameVec sz: 102386
# lines: 2034000, gameVec sz: 102438
# lines: 2035000, gameVec sz: 102489
# lines: 2036000, gameVec sz: 102541
# lines: 2037000, gameVec sz: 102593
# lines: 2038000, gameVec sz: 102643
# lines: 2039000, gameVec sz: 102697
# lines: 2040000, gameVec sz: 102750
# lines: 2041000, gameVec sz: 102802
# lines: 2042000, gameVec sz: 102853
# lines: 2043000, gameVec sz: 102904
# lines: 2044000, gameVec sz: 102956
# lines: 2045000, gameVec sz: 103006
# lines: 2046000, gameVec sz: 103057
# lines: 2047000, gameVec sz: 103109
# lines: 2048000, gameVec sz: 103159
# lines: 2049000, gameVec sz: 103210
# lines: 2050000, gameVec sz: 103265
# lines: 2051000, gameVec sz: 103318
# lines: 2052000, gameVec sz: 103369
# lines: 2053000, gameVec sz: 103422
# lines: 2054000, gameVec sz: 103473
# lines: 2055000, gameVec sz: 103525
# lines: 2056000, gameVec sz: 103578
# lines: 2057000, gameVec sz: 103632
# lines: 2058000, gameVec sz: 103685
# lines: 2059000, gameVec sz: 103737
# lines: 2060000, gameVec sz: 103789
# lines: 2061000, gameVec sz: 103843
# lines: 2062000, gameVec sz: 103894
# lines: 2063000, gameVec sz: 103947
# lines: 2064000, gameVec sz: 104000
# lines: 2065000, gameVec sz: 104051
# lines: 2066000, gameVec sz: 104103
# lines: 2067000, gameVec sz: 104153
# lines: 2068000, gameVec sz: 104203
# lines: 2069000, gameVec sz: 104251
# lines: 2070000, gameVec sz: 104301
# lines: 2071000, gameVec sz: 104348
# lines: 2072000, gameVec sz: 104399
# lines: 2073000, gameVec sz: 104453
# lines: 2074000, gameVec sz: 104504
# lines: 2075000, gameVec sz: 104553
# lines: 2076000, gameVec sz: 104606
# lines: 2077000, gameVec sz: 104661
# lines: 2078000, gameVec sz: 104716
# lines: 2079000, gameVec sz: 104766
# lines: 2080000, gameVec sz: 104819
# lines: 2081000, gameVec sz: 104870
# lines: 2082000, gameVec sz: 104918
# lines: 2083000, gameVec sz: 104969
# lines: 2084000, gameVec sz: 105022
# lines: 2085000, gameVec sz: 105074
# lines: 2086000, gameVec sz: 105127
# lines: 2087000, gameVec sz: 105178
# lines: 2088000, gameVec sz: 105230
# lines: 2089000, gameVec sz: 105283
# lines: 2090000, gameVec sz: 105336
# lines: 2091000, gameVec sz: 105390
# lines: 2092000, gameVec sz: 105442
# lines: 2093000, gameVec sz: 105495
# lines: 2094000, gameVec sz: 105548
# lines: 2095000, gameVec sz: 105597
# lines: 2096000, gameVec sz: 105646
# lines: 2097000, gameVec sz: 105698
# lines: 2098000, gameVec sz: 105750
# lines: 2099000, gameVec sz: 105804
# lines: 2100000, gameVec sz: 105857
# lines: 2101000, gameVec sz: 105909
# lines: 2102000, gameVec sz: 105962
# lines: 2103000, gameVec sz: 106016
# lines: 2104000, gameVec sz: 106067
# lines: 2105000, gameVec sz: 106119
# lines: 2106000, gameVec sz: 106172
# lines: 2107000, gameVec sz: 106225
# lines: 2108000, gameVec sz: 106278
# lines: 2109000, gameVec sz: 106329
# lines: 2110000, gameVec sz: 106383
# lines: 2111000, gameVec sz: 106434
# lines: 2112000, gameVec sz: 106489
# lines: 2113000, gameVec sz: 106541
# lines: 2114000, gameVec sz: 106592
# lines: 2115000, gameVec sz: 106643
# lines: 2116000, gameVec sz: 106696
# lines: 2117000, gameVec sz: 106747
# lines: 2118000, gameVec sz: 106799
# lines: 2119000, gameVec sz: 106852
# lines: 2120000, gameVec sz: 106905
# lines: 2121000, gameVec sz: 106958
# lines: 2122000, gameVec sz: 107009
# lines: 2123000, gameVec sz: 107063
# lines: 2124000, gameVec sz: 107116
# lines: 2125000, gameVec sz: 107167
# lines: 2126000, gameVec sz: 107219
# lines: 2127000, gameVec sz: 107271
# lines: 2128000, gameVec sz: 107322
# lines: 2129000, gameVec sz: 107376
# lines: 2130000, gameVec sz: 107429
# lines: 2131000, gameVec sz: 107482
# lines: 2132000, gameVec sz: 107536
# lines: 2133000, gameVec sz: 107589
# lines: 2134000, gameVec sz: 107639
# lines: 2135000, gameVec sz: 107694
# lines: 2136000, gameVec sz: 107746
# lines: 2137000, gameVec sz: 107798
# lines: 2138000, gameVec sz: 107850
# lines: 2139000, gameVec sz: 107901
# lines: 2140000, gameVec sz: 107953
# lines: 2141000, gameVec sz: 108003
# lines: 2142000, gameVec sz: 108057
# lines: 2143000, gameVec sz: 108111
# lines: 2144000, gameVec sz: 108164
# lines: 2145000, gameVec sz: 108215
# lines: 2146000, gameVec sz: 108267
# lines: 2147000, gameVec sz: 108319
# lines: 2148000, gameVec sz: 108374
# lines: 2149000, gameVec sz: 108426
# lines: 2150000, gameVec sz: 108479
# lines: 2151000, gameVec sz: 108532
# lines: 2152000, gameVec sz: 108585
# lines: 2153000, gameVec sz: 108638
# lines: 2154000, gameVec sz: 108691
# lines: 2155000, gameVec sz: 108743
# lines: 2156000, gameVec sz: 108796
# lines: 2157000, gameVec sz: 108851
# lines: 2158000, gameVec sz: 108906
# lines: 2159000, gameVec sz: 108957
# lines: 2160000, gameVec sz: 109007
# lines: 2161000, gameVec sz: 109061
# lines: 2162000, gameVec sz: 109116
# lines: 2163000, gameVec sz: 109169
# lines: 2164000, gameVec sz: 109223
# lines: 2165000, gameVec sz: 109277
# lines: 2166000, gameVec sz: 109329
# lines: 2167000, gameVec sz: 109381
# lines: 2168000, gameVec sz: 109434
# lines: 2169000, gameVec sz: 109486
# lines: 2170000, gameVec sz: 109538
# lines: 2171000, gameVec sz: 109589
# lines: 2172000, gameVec sz: 109641
# lines: 2173000, gameVec sz: 109694
# lines: 2174000, gameVec sz: 109747
# lines: 2175000, gameVec sz: 109798
# lines: 2176000, gameVec sz: 109850
# lines: 2177000, gameVec sz: 109899
# lines: 2178000, gameVec sz: 109950
# lines: 2179000, gameVec sz: 110000
# lines: 2180000, gameVec sz: 110051
# lines: 2181000, gameVec sz: 110103
# lines: 2182000, gameVec sz: 110155
# lines: 2183000, gameVec sz: 110205
# lines: 2184000, gameVec sz: 110257
# lines: 2185000, gameVec sz: 110309
# lines: 2186000, gameVec sz: 110363
# lines: 2187000, gameVec sz: 110415
# lines: 2188000, gameVec sz: 110464
# lines: 2189000, gameVec sz: 110516
# lines: 2190000, gameVec sz: 110565
# lines: 2191000, gameVec sz: 110616
# lines: 2192000, gameVec sz: 110664
# lines: 2193000, gameVec sz: 110713
# lines: 2194000, gameVec sz: 110764
# lines: 2195000, gameVec sz: 110813
# lines: 2196000, gameVec sz: 110867
# lines: 2197000, gameVec sz: 110918
# lines: 2198000, gameVec sz: 110969
# lines: 2199000, gameVec sz: 111023
# lines: 2200000, gameVec sz: 111075
# lines: 2201000, gameVec sz: 111125
# lines: 2202000, gameVec sz: 111178
# lines: 2203000, gameVec sz: 111231
# lines: 2204000, gameVec sz: 111284
# lines: 2205000, gameVec sz: 111335
# lines: 2206000, gameVec sz: 111386
# lines: 2207000, gameVec sz: 111436
# lines: 2208000, gameVec sz: 111488
# lines: 2209000, gameVec sz: 111541
# lines: 2210000, gameVec sz: 111592
# lines: 2211000, gameVec sz: 111644
# lines: 2212000, gameVec sz: 111696
# lines: 2213000, gameVec sz: 111751
# lines: 2214000, gameVec sz: 111803
# lines: 2215000, gameVec sz: 111856
# lines: 2216000, gameVec sz: 111909
# lines: 2217000, gameVec sz: 111963
# lines: 2218000, gameVec sz: 112017
# lines: 2219000, gameVec sz: 112067
# lines: 2220000, gameVec sz: 112118
# lines: 2221000, gameVec sz: 112169
# lines: 2222000, gameVec sz: 112222
# lines: 2223000, gameVec sz: 112275
# lines: 2224000, gameVec sz: 112330
# lines: 2225000, gameVec sz: 112380
# lines: 2226000, gameVec sz: 112432
# lines: 2227000, gameVec sz: 112486
# lines: 2228000, gameVec sz: 112540
# lines: 2229000, gameVec sz: 112594
# lines: 2230000, gameVec sz: 112648
# lines: 2231000, gameVec sz: 112698
# lines: 2232000, gameVec sz: 112749
# lines: 2233000, gameVec sz: 112802
# lines: 2234000, gameVec sz: 112854
# lines: 2235000, gameVec sz: 112909
# lines: 2236000, gameVec sz: 112959
# lines: 2237000, gameVec sz: 113011
# lines: 2238000, gameVec sz: 113063
# lines: 2239000, gameVec sz: 113115
# lines: 2240000, gameVec sz: 113166
# lines: 2241000, gameVec sz: 113221
# lines: 2242000, gameVec sz: 113273
# lines: 2243000, gameVec sz: 113324
# lines: 2244000, gameVec sz: 113375
# lines: 2245000, gameVec sz: 113430
# lines: 2246000, gameVec sz: 113482
# lines: 2247000, gameVec sz: 113532
# lines: 2248000, gameVec sz: 113584
# lines: 2249000, gameVec sz: 113634
# lines: 2250000, gameVec sz: 113688
# lines: 2251000, gameVec sz: 113739
# lines: 2252000, gameVec sz: 113792
# lines: 2253000, gameVec sz: 113844
# lines: 2254000, gameVec sz: 113895
# lines: 2255000, gameVec sz: 113949
# lines: 2256000, gameVec sz: 113999
# lines: 2257000, gameVec sz: 114052
# lines: 2258000, gameVec sz: 114106
# lines: 2259000, gameVec sz: 114160
# lines: 2260000, gameVec sz: 114210
# lines: 2261000, gameVec sz: 114262
# lines: 2262000, gameVec sz: 114314
# lines: 2263000, gameVec sz: 114364
# lines: 2264000, gameVec sz: 114415
# lines: 2265000, gameVec sz: 114466
# lines: 2266000, gameVec sz: 114517
# lines: 2267000, gameVec sz: 114568
# lines: 2268000, gameVec sz: 114619
# lines: 2269000, gameVec sz: 114670
# lines: 2270000, gameVec sz: 114719
# lines: 2271000, gameVec sz: 114770
# lines: 2272000, gameVec sz: 114822
# lines: 2273000, gameVec sz: 114872
[2019/06/22 01:29:07]
# lines: 2274000, gameVec sz: 114923
# lines: 2275000, gameVec sz: 114977
# lines: 2276000, gameVec sz: 115031
# lines: 2277000, gameVec sz: 115080
# lines: 2278000, gameVec sz: 115133
# lines: 2279000, gameVec sz: 115187
# lines: 2280000, gameVec sz: 115242
# lines: 2281000, gameVec sz: 115294
# lines: 2282000, gameVec sz: 115348
# lines: 2283000, gameVec sz: 115401
# lines: 2284000, gameVec sz: 115455
# lines: 2285000, gameVec sz: 115506
# lines: 2286000, gameVec sz: 115559
# lines: 2287000, gameVec sz: 115609
# lines: 2288000, gameVec sz: 115660
# lines: 2289000, gameVec sz: 115712
# lines: 2290000, gameVec sz: 115767
# lines: 2291000, gameVec sz: 115819
# lines: 2292000, gameVec sz: 115871
# lines: 2293000, gameVec sz: 115923
# lines: 2294000, gameVec sz: 115974
# lines: 2295000, gameVec sz: 116025
# lines: 2296000, gameVec sz: 116077
# lines: 2297000, gameVec sz: 116126
# lines: 2298000, gameVec sz: 116176
# lines: 2299000, gameVec sz: 116227
# lines: 2300000, gameVec sz: 116278
# lines: 2301000, gameVec sz: 116331
# lines: 2302000, gameVec sz: 116380
# lines: 2303000, gameVec sz: 116431
# lines: 2304000, gameVec sz: 116484
# lines: 2305000, gameVec sz: 116537
# lines: 2306000, gameVec sz: 116587
# lines: 2307000, gameVec sz: 116639
# lines: 2308000, gameVec sz: 116691
# lines: 2309000, gameVec sz: 116740
# lines: 2310000, gameVec sz: 116792
# lines: 2311000, gameVec sz: 116845
# lines: 2312000, gameVec sz: 116898
# lines: 2313000, gameVec sz: 116950
# lines: 2314000, gameVec sz: 117001
# lines: 2315000, gameVec sz: 117052
# lines: 2316000, gameVec sz: 117104
# lines: 2317000, gameVec sz: 117157
# lines: 2318000, gameVec sz: 117207
# lines: 2319000, gameVec sz: 117259
# lines: 2320000, gameVec sz: 117311
# lines: 2321000, gameVec sz: 117365
# lines: 2322000, gameVec sz: 117416
# lines: 2323000, gameVec sz: 117467
# lines: 2324000, gameVec sz: 117516
# lines: 2325000, gameVec sz: 117568
# lines: 2326000, gameVec sz: 117620
# lines: 2327000, gameVec sz: 117672
# lines: 2328000, gameVec sz: 117723
# lines: 2329000, gameVec sz: 117775
# lines: 2330000, gameVec sz: 117829
# lines: 2331000, gameVec sz: 117880
# lines: 2332000, gameVec sz: 117932
# lines: 2333000, gameVec sz: 117985
# lines: 2334000, gameVec sz: 118037
# lines: 2335000, gameVec sz: 118087
# lines: 2336000, gameVec sz: 118138
# lines: 2337000, gameVec sz: 118190
# lines: 2338000, gameVec sz: 118240
# lines: 2339000, gameVec sz: 118291
# lines: 2340000, gameVec sz: 118345
# lines: 2341000, gameVec sz: 118395
# lines: 2342000, gameVec sz: 118447
# lines: 2343000, gameVec sz: 118500
# lines: 2344000, gameVec sz: 118554
# lines: 2345000, gameVec sz: 118605
# lines: 2346000, gameVec sz: 118659
# lines: 2347000, gameVec sz: 118711
# lines: 2348000, gameVec sz: 118764
# lines: 2349000, gameVec sz: 118815
# lines: 2350000, gameVec sz: 118866
# lines: 2351000, gameVec sz: 118918
# lines: 2352000, gameVec sz: 118970
# lines: 2353000, gameVec sz: 119022
# lines: 2354000, gameVec sz: 119075
# lines: 2355000, gameVec sz: 119126
# lines: 2356000, gameVec sz: 119179
# lines: 2357000, gameVec sz: 119233
# lines: 2358000, gameVec sz: 119286
# lines: 2359000, gameVec sz: 119338
# lines: 2360000, gameVec sz: 119389
# lines: 2361000, gameVec sz: 119442
# lines: 2362000, gameVec sz: 119492
# lines: 2363000, gameVec sz: 119544
# lines: 2364000, gameVec sz: 119595
# lines: 2365000, gameVec sz: 119646
# lines: 2366000, gameVec sz: 119697
# lines: 2367000, gameVec sz: 119747
# lines: 2368000, gameVec sz: 119799
# lines: 2369000, gameVec sz: 119850
# lines: 2370000, gameVec sz: 119903
# lines: 2371000, gameVec sz: 119954
# lines: 2372000, gameVec sz: 120005
# lines: 2373000, gameVec sz: 120058
# lines: 2374000, gameVec sz: 120107
# lines: 2375000, gameVec sz: 120158
# lines: 2376000, gameVec sz: 120209
# lines: 2377000, gameVec sz: 120261
# lines: 2378000, gameVec sz: 120313
# lines: 2379000, gameVec sz: 120364
# lines: 2380000, gameVec sz: 120416
# lines: 2381000, gameVec sz: 120466
# lines: 2382000, gameVec sz: 120517
# lines: 2383000, gameVec sz: 120569
# lines: 2384000, gameVec sz: 120620
# lines: 2385000, gameVec sz: 120674
# lines: 2386000, gameVec sz: 120725
# lines: 2387000, gameVec sz: 120777
# lines: 2388000, gameVec sz: 120829
# lines: 2389000, gameVec sz: 120881
# lines: 2390000, gameVec sz: 120934
# lines: 2391000, gameVec sz: 120986
# lines: 2392000, gameVec sz: 121039
# lines: 2393000, gameVec sz: 121090
# lines: 2394000, gameVec sz: 121141
# lines: 2395000, gameVec sz: 121193
# lines: 2396000, gameVec sz: 121244
# lines: 2397000, gameVec sz: 121295
# lines: 2398000, gameVec sz: 121347
# lines: 2399000, gameVec sz: 121401
# lines: 2400000, gameVec sz: 121454
# lines: 2401000, gameVec sz: 121504
# lines: 2402000, gameVec sz: 121557
# lines: 2403000, gameVec sz: 121608
# lines: 2404000, gameVec sz: 121658
# lines: 2405000, gameVec sz: 121709
# lines: 2406000, gameVec sz: 121762
# lines: 2407000, gameVec sz: 121814
# lines: 2408000, gameVec sz: 121867
# lines: 2409000, gameVec sz: 121918
# lines: 2410000, gameVec sz: 121973
# lines: 2411000, gameVec sz: 122024
# lines: 2412000, gameVec sz: 122075
# lines: 2413000, gameVec sz: 122124
# lines: 2414000, gameVec sz: 122175
# lines: 2415000, gameVec sz: 122225
# lines: 2416000, gameVec sz: 122278
# lines: 2417000, gameVec sz: 122327
# lines: 2418000, gameVec sz: 122379
# lines: 2419000, gameVec sz: 122430
# lines: 2420000, gameVec sz: 122485
# lines: 2421000, gameVec sz: 122537
# lines: 2422000, gameVec sz: 122589
# lines: 2423000, gameVec sz: 122641
# lines: 2424000, gameVec sz: 122692
# lines: 2425000, gameVec sz: 122744
# lines: 2426000, gameVec sz: 122795
# lines: 2427000, gameVec sz: 122847
# lines: 2428000, gameVec sz: 122900
# lines: 2429000, gameVec sz: 122952
# lines: 2430000, gameVec sz: 123005
# lines: 2431000, gameVec sz: 123057
# lines: 2432000, gameVec sz: 123110
# lines: 2433000, gameVec sz: 123162
# lines: 2434000, gameVec sz: 123214
# lines: 2435000, gameVec sz: 123264
# lines: 2436000, gameVec sz: 123317
# lines: 2437000, gameVec sz: 123369
# lines: 2438000, gameVec sz: 123420
# lines: 2439000, gameVec sz: 123473
# lines: 2440000, gameVec sz: 123524
# lines: 2441000, gameVec sz: 123577
# lines: 2442000, gameVec sz: 123630
# lines: 2443000, gameVec sz: 123683
# lines: 2444000, gameVec sz: 123733
# lines: 2445000, gameVec sz: 123785
# lines: 2446000, gameVec sz: 123836
# lines: 2447000, gameVec sz: 123889
# lines: 2448000, gameVec sz: 123940
# lines: 2449000, gameVec sz: 123992
# lines: 2450000, gameVec sz: 124043
# lines: 2451000, gameVec sz: 124094
# lines: 2452000, gameVec sz: 124146
# lines: 2453000, gameVec sz: 124200
# lines: 2454000, gameVec sz: 124254
# lines: 2455000, gameVec sz: 124308
# lines: 2456000, gameVec sz: 124363
# lines: 2457000, gameVec sz: 124416
# lines: 2458000, gameVec sz: 124468
# lines: 2459000, gameVec sz: 124519
# lines: 2460000, gameVec sz: 124570
# lines: 2461000, gameVec sz: 124623
# lines: 2462000, gameVec sz: 124675
# lines: 2463000, gameVec sz: 124726
# lines: 2464000, gameVec sz: 124777
# lines: 2465000, gameVec sz: 124829
# lines: 2466000, gameVec sz: 124879
# lines: 2467000, gameVec sz: 124930
# lines: 2468000, gameVec sz: 124982
# lines: 2469000, gameVec sz: 125032
# lines: 2470000, gameVec sz: 125086
# lines: 2471000, gameVec sz: 125137
# lines: 2472000, gameVec sz: 125188
# lines: 2473000, gameVec sz: 125238
# lines: 2474000, gameVec sz: 125289
# lines: 2475000, gameVec sz: 125339
# lines: 2476000, gameVec sz: 125390
# lines: 2477000, gameVec sz: 125441
# lines: 2478000, gameVec sz: 125492
# lines: 2479000, gameVec sz: 125545
# lines: 2480000, gameVec sz: 125596
# lines: 2481000, gameVec sz: 125646
# lines: 2482000, gameVec sz: 125697
# lines: 2483000, gameVec sz: 125748
# lines: 2484000, gameVec sz: 125798
# lines: 2485000, gameVec sz: 125850
# lines: 2486000, gameVec sz: 125900
# lines: 2487000, gameVec sz: 125951
# lines: 2488000, gameVec sz: 126003
# lines: 2489000, gameVec sz: 126056
# lines: 2490000, gameVec sz: 126109
# lines: 2491000, gameVec sz: 126161
# lines: 2492000, gameVec sz: 126213
# lines: 2493000, gameVec sz: 126264
# lines: 2494000, gameVec sz: 126315
# lines: 2495000, gameVec sz: 126367
# lines: 2496000, gameVec sz: 126419
# lines: 2497000, gameVec sz: 126469
# lines: 2498000, gameVec sz: 126520
# lines: 2499000, gameVec sz: 126571
# lines: 2500000, gameVec sz: 126623
# lines: 2501000, gameVec sz: 126674
# lines: 2502000, gameVec sz: 126725
# lines: 2503000, gameVec sz: 126777
# lines: 2504000, gameVec sz: 126827
# lines: 2505000, gameVec sz: 126881
# lines: 2506000, gameVec sz: 126932
# lines: 2507000, gameVec sz: 126983
# lines: 2508000, gameVec sz: 127034
# lines: 2509000, gameVec sz: 127087
# lines: 2510000, gameVec sz: 127140
# lines: 2511000, gameVec sz: 127192
# lines: 2512000, gameVec sz: 127242
# lines: 2513000, gameVec sz: 127295
# lines: 2514000, gameVec sz: 127346
# lines: 2515000, gameVec sz: 127395
# lines: 2516000, gameVec sz: 127445
# lines: 2517000, gameVec sz: 127495
# lines: 2518000, gameVec sz: 127546
# lines: 2519000, gameVec sz: 127598
# lines: 2520000, gameVec sz: 127650
# lines: 2521000, gameVec sz: 127703
# lines: 2522000, gameVec sz: 127755
# lines: 2523000, gameVec sz: 127807
# lines: 2524000, gameVec sz: 127859
# lines: 2525000, gameVec sz: 127911
# lines: 2526000, gameVec sz: 127962
# lines: 2527000, gameVec sz: 128012
# lines: 2528000, gameVec sz: 128063
# lines: 2529000, gameVec sz: 128115
# lines: 2530000, gameVec sz: 128168
# lines: 2531000, gameVec sz: 128217
# lines: 2532000, gameVec sz: 128268
# lines: 2533000, gameVec sz: 128321
# lines: 2534000, gameVec sz: 128374
# lines: 2535000, gameVec sz: 128426
# lines: 2536000, gameVec sz: 128478
[2019/06/22 01:29:08]
# lines: 2537000, gameVec sz: 128529
# lines: 2538000, gameVec sz: 128580
# lines: 2539000, gameVec sz: 128631
# lines: 2540000, gameVec sz: 128684
# lines: 2541000, gameVec sz: 128737
# lines: 2542000, gameVec sz: 128789
# lines: 2543000, gameVec sz: 128841
# lines: 2544000, gameVec sz: 128891
# lines: 2545000, gameVec sz: 128942
# lines: 2546000, gameVec sz: 128994
# lines: 2547000, gameVec sz: 129046
# lines: 2548000, gameVec sz: 129098
# lines: 2549000, gameVec sz: 129150
# lines: 2550000, gameVec sz: 129203
# lines: 2551000, gameVec sz: 129256
# lines: 2552000, gameVec sz: 129310
# lines: 2553000, gameVec sz: 129364
# lines: 2554000, gameVec sz: 129415
# lines: 2555000, gameVec sz: 129466
# lines: 2556000, gameVec sz: 129517
# lines: 2557000, gameVec sz: 129569
# lines: 2558000, gameVec sz: 129624
# lines: 2559000, gameVec sz: 129678
# lines: 2560000, gameVec sz: 129732
# lines: 2561000, gameVec sz: 129785
# lines: 2562000, gameVec sz: 129840
# lines: 2563000, gameVec sz: 129894
# lines: 2564000, gameVec sz: 129948
# lines: 2565000, gameVec sz: 130001
# lines: 2566000, gameVec sz: 130052
# lines: 2567000, gameVec sz: 130105
# lines: 2568000, gameVec sz: 130159
# lines: 2569000, gameVec sz: 130211
# lines: 2570000, gameVec sz: 130261
# lines: 2571000, gameVec sz: 130312
# lines: 2572000, gameVec sz: 130365
# lines: 2573000, gameVec sz: 130416
# lines: 2574000, gameVec sz: 130467
# lines: 2575000, gameVec sz: 130516
# lines: 2576000, gameVec sz: 130569
# lines: 2577000, gameVec sz: 130622
# lines: 2578000, gameVec sz: 130673
# lines: 2579000, gameVec sz: 130725
# lines: 2580000, gameVec sz: 130778
# lines: 2581000, gameVec sz: 130829
# lines: 2582000, gameVec sz: 130882
# lines: 2583000, gameVec sz: 130934
# lines: 2584000, gameVec sz: 130987
# lines: 2585000, gameVec sz: 131038
# lines: 2586000, gameVec sz: 131090
# lines: 2587000, gameVec sz: 131143
# lines: 2588000, gameVec sz: 131196
# lines: 2589000, gameVec sz: 131246
# lines: 2590000, gameVec sz: 131298
# lines: 2591000, gameVec sz: 131349
# lines: 2592000, gameVec sz: 131400
# lines: 2593000, gameVec sz: 131453
# lines: 2594000, gameVec sz: 131505
# lines: 2595000, gameVec sz: 131556
# lines: 2596000, gameVec sz: 131607
# lines: 2597000, gameVec sz: 131660
# lines: 2598000, gameVec sz: 131714
# lines: 2599000, gameVec sz: 131766
# lines: 2600000, gameVec sz: 131819
# lines: 2601000, gameVec sz: 131870
# lines: 2602000, gameVec sz: 131922
# lines: 2603000, gameVec sz: 131973
# lines: 2604000, gameVec sz: 132024
# lines: 2605000, gameVec sz: 132074
# lines: 2606000, gameVec sz: 132125
# lines: 2607000, gameVec sz: 132178
# lines: 2608000, gameVec sz: 132229
# lines: 2609000, gameVec sz: 132282
# lines: 2610000, gameVec sz: 132334
# lines: 2611000, gameVec sz: 132385
# lines: 2612000, gameVec sz: 132438
# lines: 2613000, gameVec sz: 132490
# lines: 2614000, gameVec sz: 132540
# lines: 2615000, gameVec sz: 132592
# lines: 2616000, gameVec sz: 132643
# lines: 2617000, gameVec sz: 132694
# lines: 2618000, gameVec sz: 132747
# lines: 2619000, gameVec sz: 132799
# lines: 2620000, gameVec sz: 132851
# lines: 2621000, gameVec sz: 132901
# lines: 2622000, gameVec sz: 132952
# lines: 2623000, gameVec sz: 133002
# lines: 2624000, gameVec sz: 133054
# lines: 2625000, gameVec sz: 133105
# lines: 2626000, gameVec sz: 133156
# lines: 2627000, gameVec sz: 133208
# lines: 2628000, gameVec sz: 133262
# lines: 2629000, gameVec sz: 133315
# lines: 2630000, gameVec sz: 133367
# lines: 2631000, gameVec sz: 133419
# lines: 2632000, gameVec sz: 133470
# lines: 2633000, gameVec sz: 133523
# lines: 2634000, gameVec sz: 133574
# lines: 2635000, gameVec sz: 133625
# lines: 2636000, gameVec sz: 133677
# lines: 2637000, gameVec sz: 133730
# lines: 2638000, gameVec sz: 133783
# lines: 2639000, gameVec sz: 133835
# lines: 2640000, gameVec sz: 133885
# lines: 2641000, gameVec sz: 133937
# lines: 2642000, gameVec sz: 133989
# lines: 2643000, gameVec sz: 134040
# lines: 2644000, gameVec sz: 134093
# lines: 2645000, gameVec sz: 134145
# lines: 2646000, gameVec sz: 134197
# lines: 2647000, gameVec sz: 134249
# lines: 2648000, gameVec sz: 134303
# lines: 2649000, gameVec sz: 134355
# lines: 2650000, gameVec sz: 134408
# lines: 2651000, gameVec sz: 134461
# lines: 2652000, gameVec sz: 134512
# lines: 2653000, gameVec sz: 134563
# lines: 2654000, gameVec sz: 134617
# lines: 2655000, gameVec sz: 134668
# lines: 2656000, gameVec sz: 134719
# lines: 2657000, gameVec sz: 134769
# lines: 2658000, gameVec sz: 134821
# lines: 2659000, gameVec sz: 134871
# lines: 2660000, gameVec sz: 134923
# lines: 2661000, gameVec sz: 134977
# lines: 2662000, gameVec sz: 135029
# lines: 2663000, gameVec sz: 135081
# lines: 2664000, gameVec sz: 135134
# lines: 2665000, gameVec sz: 135186
# lines: 2666000, gameVec sz: 135239
# lines: 2667000, gameVec sz: 135292
# lines: 2668000, gameVec sz: 135343
# lines: 2669000, gameVec sz: 135395
# lines: 2670000, gameVec sz: 135447
# lines: 2671000, gameVec sz: 135498
# lines: 2672000, gameVec sz: 135552
# lines: 2673000, gameVec sz: 135606
# lines: 2674000, gameVec sz: 135659
# lines: 2675000, gameVec sz: 135712
# lines: 2676000, gameVec sz: 135765
# lines: 2677000, gameVec sz: 135818
# lines: 2678000, gameVec sz: 135868
# lines: 2679000, gameVec sz: 135920
# lines: 2680000, gameVec sz: 135971
# lines: 2681000, gameVec sz: 136023
# lines: 2682000, gameVec sz: 136074
# lines: 2683000, gameVec sz: 136123
# lines: 2684000, gameVec sz: 136172
# lines: 2685000, gameVec sz: 136223
# lines: 2686000, gameVec sz: 136274
# lines: 2687000, gameVec sz: 136324
# lines: 2688000, gameVec sz: 136375
# lines: 2689000, gameVec sz: 136425
# lines: 2690000, gameVec sz: 136477
# lines: 2691000, gameVec sz: 136530
# lines: 2692000, gameVec sz: 136582
# lines: 2693000, gameVec sz: 136635
# lines: 2694000, gameVec sz: 136689
# lines: 2695000, gameVec sz: 136740
# lines: 2696000, gameVec sz: 136791
# lines: 2697000, gameVec sz: 136843
# lines: 2698000, gameVec sz: 136895
# lines: 2699000, gameVec sz: 136948
# lines: 2700000, gameVec sz: 136999
# lines: 2701000, gameVec sz: 137049
# lines: 2702000, gameVec sz: 137101
# lines: 2703000, gameVec sz: 137151
# lines: 2704000, gameVec sz: 137203
# lines: 2705000, gameVec sz: 137254
# lines: 2706000, gameVec sz: 137306
# lines: 2707000, gameVec sz: 137361
# lines: 2708000, gameVec sz: 137413
# lines: 2709000, gameVec sz: 137464
# lines: 2710000, gameVec sz: 137516
# lines: 2711000, gameVec sz: 137569
# lines: 2712000, gameVec sz: 137622
# lines: 2713000, gameVec sz: 137673
# lines: 2714000, gameVec sz: 137724
# lines: 2715000, gameVec sz: 137776
# lines: 2716000, gameVec sz: 137826
# lines: 2717000, gameVec sz: 137880
# lines: 2718000, gameVec sz: 137933
# lines: 2719000, gameVec sz: 137985
# lines: 2720000, gameVec sz: 138037
# lines: 2721000, gameVec sz: 138088
# lines: 2722000, gameVec sz: 138139
# lines: 2723000, gameVec sz: 138191
# lines: 2724000, gameVec sz: 138242
# lines: 2725000, gameVec sz: 138294
# lines: 2726000, gameVec sz: 138345
# lines: 2727000, gameVec sz: 138396
# lines: 2728000, gameVec sz: 138449
# lines: 2729000, gameVec sz: 138500
# lines: 2730000, gameVec sz: 138552
# lines: 2731000, gameVec sz: 138604
# lines: 2732000, gameVec sz: 138657
# lines: 2733000, gameVec sz: 138707
# lines: 2734000, gameVec sz: 138759
# lines: 2735000, gameVec sz: 138810
# lines: 2736000, gameVec sz: 138858
# lines: 2737000, gameVec sz: 138911
# lines: 2738000, gameVec sz: 138963
# lines: 2739000, gameVec sz: 139014
# lines: 2740000, gameVec sz: 139065
# lines: 2741000, gameVec sz: 139115
# lines: 2742000, gameVec sz: 139167
# lines: 2743000, gameVec sz: 139220
# lines: 2744000, gameVec sz: 139271
# lines: 2745000, gameVec sz: 139323
# lines: 2746000, gameVec sz: 139372
# lines: 2747000, gameVec sz: 139423
# lines: 2748000, gameVec sz: 139473
# lines: 2749000, gameVec sz: 139523
# lines: 2750000, gameVec sz: 139574
# lines: 2751000, gameVec sz: 139626
# lines: 2752000, gameVec sz: 139679
# lines: 2753000, gameVec sz: 139732
# lines: 2754000, gameVec sz: 139781
# lines: 2755000, gameVec sz: 139832
# lines: 2756000, gameVec sz: 139882
# lines: 2757000, gameVec sz: 139934
# lines: 2758000, gameVec sz: 139987
# lines: 2759000, gameVec sz: 140038
# lines: 2760000, gameVec sz: 140088
# lines: 2761000, gameVec sz: 140140
# lines: 2762000, gameVec sz: 140191
# lines: 2763000, gameVec sz: 140245
# lines: 2764000, gameVec sz: 140298
# lines: 2765000, gameVec sz: 140350
# lines: 2766000, gameVec sz: 140403
# lines: 2767000, gameVec sz: 140456
# lines: 2768000, gameVec sz: 140509
# lines: 2769000, gameVec sz: 140558
# lines: 2770000, gameVec sz: 140611
# lines: 2771000, gameVec sz: 140662
# lines: 2772000, gameVec sz: 140714
# lines: 2773000, gameVec sz: 140766
gamevec sz: 140785
#GameParser::parsePGN
game: (0/140785)
numPositions: 0
game: (100/140785)
numPositions: 9084
[2019/06/22 01:29:09]
game: (200/140785)
numPositions: 19381
game: (300/140785)
numPositions: 28366
game: (400/140785)
numPositions: 37792
game: (500/140785)
numPositions: 47343
game: (600/140785)
numPositions: 56827
game: (700/140785)
numPositions: 66025
game: (800/140785)
numPositions: 75465
game: (900/140785)
numPositions: 84495
game: (1000/140785)
numPositions: 93272
game: (1100/140785)
numPositions: 101848
game: (1200/140785)
numPositions: 110754
game: (1300/140785)
numPositions: 119397
game: (1400/140785)
numPositions: 128685
game: (1500/140785)
numPositions: 137417
game: (1600/140785)
numPositions: 145365
game: (1700/140785)
numPositions: 153141
game: (1800/140785)
numPositions: 161817
[2019/06/22 01:29:10]
game: (1900/140785)
numPositions: 170085
game: (2000/140785)
numPositions: 178279
game: (2100/140785)
numPositions: 186900
game: (2200/140785)
numPositions: 195741
game: (2300/140785)
numPositions: 205151
game: (2400/140785)
numPositions: 214162
game: (2500/140785)
numPositions: 222372
game: (2600/140785)
numPositions: 230634
game: (2700/140785)
numPositions: 239231
game: (2800/140785)
numPositions: 247876
game: (2900/140785)
numPositions: 256784
game: (3000/140785)
numPositions: 265837
game: (3100/140785)
numPositions: 275434
game: (3200/140785)
numPositions: 284791
game: (3300/140785)
numPositions: 293691
game: (3400/140785)
numPositions: 302643
game: (3500/140785)
numPositions: 311996
game: (3600/140785)
numPositions: 320892
[2019/06/22 01:29:11]
game: (3700/140785)
numPositions: 330062
game: (3800/140785)
numPositions: 337542
game: (3900/140785)
numPositions: 345625
game: (4000/140785)
numPositions: 353551
game: (4100/140785)
numPositions: 362066
game: (4200/140785)
numPositions: 370843
game: (4300/140785)
numPositions: 379958
game: (4400/140785)
numPositions: 387811
game: (4500/140785)
numPositions: 397102
game: (4600/140785)
numPositions: 405381
game: (4700/140785)
numPositions: 413875
game: (4800/140785)
numPositions: 422433
game: (4900/140785)
numPositions: 430747
game: (5000/140785)
numPositions: 439071
game: (5100/140785)
numPositions: 447681
game: (5200/140785)
numPositions: 456865
game: (5300/140785)
numPositions: 465593
game: (5400/140785)
numPositions: 474474
game: (5500/140785)
numPositions: 483203
[2019/06/22 01:29:12]
game: (5600/140785)
numPositions: 491898
game: (5700/140785)
numPositions: 500237
game: (5800/140785)
numPositions: 508426
game: (5900/140785)
numPositions: 517054
game: (6000/140785)
numPositions: 526082
game: (6100/140785)
numPositions: 533793
game: (6200/140785)
numPositions: 542086
game: (6300/140785)
numPositions: 550633
game: (6400/140785)
numPositions: 559532
game: (6500/140785)
numPositions: 568509
game: (6600/140785)
numPositions: 576534
game: (6700/140785)
numPositions: 584371
game: (6800/140785)
numPositions: 592608
game: (6900/140785)
numPositions: 601117
game: (7000/140785)
numPositions: 609732
game: (7100/140785)
numPositions: 618435
game: (7200/140785)
numPositions: 626927
game: (7300/140785)
numPositions: 635960
game: (7400/140785)
numPositions: 644362
[2019/06/22 01:29:13]
game: (7500/140785)
numPositions: 652517
game: (7600/140785)
numPositions: 660267
game: (7700/140785)
numPositions: 668552
game: (7800/140785)
numPositions: 677575
game: (7900/140785)
numPositions: 686521
game: (8000/140785)
numPositions: 695047
game: (8100/140785)
numPositions: 703062
game: (8200/140785)
numPositions: 710569
game: (8300/140785)
numPositions: 719262
game: (8400/140785)
numPositions: 728642
game: (8500/140785)
numPositions: 736973
game: (8600/140785)
numPositions: 745784
game: (8700/140785)
numPositions: 755327
game: (8800/140785)
numPositions: 763840
game: (8900/140785)
numPositions: 772387
game: (9000/140785)
numPositions: 780970
game: (9100/140785)
numPositions: 789970
game: (9200/140785)
numPositions: 798513
[2019/06/22 01:29:14]
game: (9300/140785)
numPositions: 807160
game: (9400/140785)
numPositions: 815759
game: (9500/140785)
numPositions: 825148
game: (9600/140785)
numPositions: 833102
game: (9700/140785)
numPositions: 841972
game: (9800/140785)
numPositions: 850611
game: (9900/140785)
numPositions: 859822
game: (10000/140785)
numPositions: 868340
game: (10100/140785)
numPositions: 876253
game: (10200/140785)
numPositions: 884252
game: (10300/140785)
numPositions: 892470
game: (10400/140785)
numPositions: 900927
game: (10500/140785)
numPositions: 910488
game: (10600/140785)
numPositions: 919072
game: (10700/140785)
numPositions: 927858
game: (10800/140785)
numPositions: 936696
game: (10900/140785)
numPositions: 945520
[2019/06/22 01:29:15]
game: (11000/140785)
numPositions: 954585
game: (11100/140785)
numPositions: 963453
game: (11200/140785)
numPositions: 972594
game: (11300/140785)
numPositions: 981118
game: (11400/140785)
numPositions: 990157
game: (11500/140785)
numPositions: 999061
game: (11600/140785)
numPositions: 1007730
game: (11700/140785)
numPositions: 1016540
game: (11800/140785)
numPositions: 1025806
game: (11900/140785)
numPositions: 1035340
game: (12000/140785)
numPositions: 1045523
game: (12100/140785)
numPositions: 1054126
game: (12200/140785)
numPositions: 1063971
game: (12300/140785)
numPositions: 1073363
game: (12400/140785)
numPositions: 1083844
game: (12500/140785)
numPositions: 1093039
game: (12600/140785)
numPositions: 1102127
game: (12700/140785)
numPositions: 1111583
[2019/06/22 01:29:16]
game: (12800/140785)
numPositions: 1120625
game: (12900/140785)
numPositions: 1129900
game: (13000/140785)
numPositions: 1139551
game: (13100/140785)
numPositions: 1148447
game: (13200/140785)
numPositions: 1157337
game: (13300/140785)
numPositions: 1166006
game: (13400/140785)
numPositions: 1174898
game: (13500/140785)
numPositions: 1183456
game: (13600/140785)
numPositions: 1191885
game: (13700/140785)
numPositions: 1200442
game: (13800/140785)
numPositions: 1208427
game: (13900/140785)
numPositions: 1217253
game: (14000/140785)
numPositions: 1226144
game: (14100/140785)
numPositions: 1234639
game: (14200/140785)
numPositions: 1243056
game: (14300/140785)
numPositions: 1252175
game: (14400/140785)
numPositions: 1260477
game: (14500/140785)
numPositions: 1269924
[2019/06/22 01:29:17]
game: (14600/140785)
numPositions: 1278296
game: (14700/140785)
numPositions: 1286791
game: (14800/140785)
numPositions: 1294939
game: (14900/140785)
numPositions: 1304591
game: (15000/140785)
numPositions: 1313030
game: (15100/140785)
numPositions: 1322732
game: (15200/140785)
numPositions: 1331485
game: (15300/140785)
numPositions: 1340265
game: (15400/140785)
numPositions: 1348698
game: (15500/140785)
numPositions: 1357092
game: (15600/140785)
numPositions: 1364743
game: (15700/140785)
numPositions: 1373455
game: (15800/140785)
numPositions: 1381615
game: (15900/140785)
numPositions: 1390538
game: (16000/140785)
numPositions: 1398597
game: (16100/140785)
numPositions: 1406902
game: (16200/140785)
numPositions: 1414905
game: (16300/140785)
numPositions: 1422764
game: (16400/140785)
numPositions: 1431260
[2019/06/22 01:29:18]
game: (16500/140785)
numPositions: 1439577
game: (16600/140785)
numPositions: 1449280
game: (16700/140785)
numPositions: 1457918
game: (16800/140785)
numPositions: 1467109
game: (16900/140785)
numPositions: 1475961
game: (17000/140785)
numPositions: 1484187
game: (17100/140785)
numPositions: 1492957
game: (17200/140785)
numPositions: 1501638
game: (17300/140785)
numPositions: 1510151
game: (17400/140785)
numPositions: 1518780
game: (17500/140785)
numPositions: 1527464
game: (17600/140785)
numPositions: 1535867
game: (17700/140785)
numPositions: 1545141
game: (17800/140785)
numPositions: 1554091
game: (17900/140785)
numPositions: 1562741
game: (18000/140785)
numPositions: 1571470
game: (18100/140785)
numPositions: 1580344
game: (18200/140785)
numPositions: 1589618
[2019/06/22 01:29:19]
game: (18300/140785)
numPositions: 1598419
game: (18400/140785)
numPositions: 1607096
game: (18500/140785)
numPositions: 1616512
game: (18600/140785)
numPositions: 1624516
game: (18700/140785)
numPositions: 1633047
game: (18800/140785)
numPositions: 1641692
game: (18900/140785)
numPositions: 1650551
game: (19000/140785)
numPositions: 1658619
game: (19100/140785)
numPositions: 1667131
game: (19200/140785)
numPositions: 1675551
game: (19300/140785)
numPositions: 1684591
game: (19400/140785)
numPositions: 1693793
game: (19500/140785)
numPositions: 1702779
game: (19600/140785)
numPositions: 1710823
game: (19700/140785)
numPositions: 1719248
game: (19800/140785)
numPositions: 1727242
game: (19900/140785)
numPositions: 1736254
[2019/06/22 01:29:20]
game: (20000/140785)
numPositions: 1744683
game: (20100/140785)
numPositions: 1752702
game: (20200/140785)
numPositions: 1760916
game: (20300/140785)
numPositions: 1769329
game: (20400/140785)
numPositions: 1777632
game: (20500/140785)
numPositions: 1785639
game: (20600/140785)
numPositions: 1794252
game: (20700/140785)
numPositions: 1802849
game: (20800/140785)
numPositions: 1810790
game: (20900/140785)
numPositions: 1819479
game: (21000/140785)
numPositions: 1828705
game: (21100/140785)
numPositions: 1837778
game: (21200/140785)
numPositions: 1847171
game: (21300/140785)
numPositions: 1856037
game: (21400/140785)
numPositions: 1864776
game: (21500/140785)
numPositions: 1873900
game: (21600/140785)
numPositions: 1882603
game: (21700/140785)
numPositions: 1891434
game: (21800/140785)
numPositions: 1900277
[2019/06/22 01:29:21]
game: (21900/140785)
numPositions: 1908682
game: (22000/140785)
numPositions: 1917587
game: (22100/140785)
numPositions: 1925915
game: (22200/140785)
numPositions: 1934717
game: (22300/140785)
numPositions: 1943996
game: (22400/140785)
numPositions: 1953105
game: (22500/140785)
numPositions: 1961382
game: (22600/140785)
numPositions: 1970463
game: (22700/140785)
numPositions: 1980748
game: (22800/140785)
numPositions: 1990347
game: (22900/140785)
numPositions: 1999650
game: (23000/140785)
numPositions: 2009436
game: (23100/140785)
numPositions: 2017916
game: (23200/140785)
numPositions: 2026712
game: (23300/140785)
numPositions: 2036079
game: (23400/140785)
numPositions: 2044847
game: (23500/140785)
numPositions: 2052880
game: (23600/140785)
numPositions: 2061607
[2019/06/22 01:29:22]
game: (23700/140785)
numPositions: 2070572
game: (23800/140785)
numPositions: 2079493
game: (23900/140785)
numPositions: 2087799
game: (24000/140785)
numPositions: 2095833
game: (24100/140785)
numPositions: 2104397
game: (24200/140785)
numPositions: 2113117
game: (24300/140785)
numPositions: 2121115
game: (24400/140785)
numPositions: 2129491
game: (24500/140785)
numPositions: 2138360
game: (24600/140785)
numPositions: 2147075
game: (24700/140785)
numPositions: 2155478
game: (24800/140785)
numPositions: 2164478
game: (24900/140785)
numPositions: 2173093
game: (25000/140785)
numPositions: 2180945
game: (25100/140785)
numPositions: 2189478
game: (25200/140785)
numPositions: 2198438
game: (25300/140785)
numPositions: 2207391
game: (25400/140785)
numPositions: 2215724
[2019/06/22 01:29:23]
game: (25500/140785)
numPositions: 2223666
game: (25600/140785)
numPositions: 2231907
game: (25700/140785)
numPositions: 2239810
game: (25800/140785)
numPositions: 2247464
game: (25900/140785)
numPositions: 2256417
game: (26000/140785)
numPositions: 2266053
game: (26100/140785)
numPositions: 2275353
game: (26200/140785)
numPositions: 2283773
game: (26300/140785)
numPositions: 2291750
game: (26400/140785)
numPositions: 2300154
game: (26500/140785)
numPositions: 2309134
game: (26600/140785)
numPositions: 2317453
game: (26700/140785)
numPositions: 2326057
game: (26800/140785)
numPositions: 2334792
game: (26900/140785)
numPositions: 2342617
game: (27000/140785)
numPositions: 2351112
game: (27100/140785)
numPositions: 2359600
game: (27200/140785)
numPositions: 2368173
game: (27300/140785)
numPositions: 2376669
[2019/06/22 01:29:24]
game: (27400/140785)
numPositions: 2385486
game: (27500/140785)
numPositions: 2393958
game: (27600/140785)
numPositions: 2402462
game: (27700/140785)
numPositions: 2411444
game: (27800/140785)
numPositions: 2420181
game: (27900/140785)
numPositions: 2428875
game: (28000/140785)
numPositions: 2437122
game: (28100/140785)
numPositions: 2445610
game: (28200/140785)
numPositions: 2453950
game: (28300/140785)
numPositions: 2462768
game: (28400/140785)
numPositions: 2472234
game: (28500/140785)
numPositions: 2481596
game: (28600/140785)
numPositions: 2490642
game: (28700/140785)
numPositions: 2498917
game: (28800/140785)
numPositions: 2507698
game: (28900/140785)
numPositions: 2517156
game: (29000/140785)
numPositions: 2525967
game: (29100/140785)
numPositions: 2533778
[2019/06/22 01:29:25]
game: (29200/140785)
numPositions: 2542544
game: (29300/140785)
numPositions: 2551099
game: (29400/140785)
numPositions: 2559804
game: (29500/140785)
numPositions: 2568689
game: (29600/140785)
numPositions: 2577560
game: (29700/140785)
numPositions: 2586347
game: (29800/140785)
numPositions: 2595183
game: (29900/140785)
numPositions: 2603663
game: (30000/140785)
numPositions: 2612131
game: (30100/140785)
numPositions: 2620769
game: (30200/140785)
numPositions: 2628883
game: (30300/140785)
numPositions: 2636653
game: (30400/140785)
numPositions: 2645067
game: (30500/140785)
numPositions: 2654451
game: (30600/140785)
numPositions: 2663077
game: (30700/140785)
numPositions: 2671397
game: (30800/140785)
numPositions: 2680967
game: (30900/140785)
numPositions: 2690717
[2019/06/22 01:29:26]
game: (31000/140785)
numPositions: 2699309
game: (31100/140785)
numPositions: 2708274
game: (31200/140785)
numPositions: 2716326
game: (31300/140785)
numPositions: 2725192
game: (31400/140785)
numPositions: 2733638
game: (31500/140785)
numPositions: 2742944
game: (31600/140785)
numPositions: 2751083
game: (31700/140785)
numPositions: 2759059
game: (31800/140785)
numPositions: 2767633
game: (31900/140785)
numPositions: 2776123
game: (32000/140785)
numPositions: 2784807
game: (32100/140785)
numPositions: 2793366
game: (32200/140785)
numPositions: 2802096
game: (32300/140785)
numPositions: 2811137
game: (32400/140785)
numPositions: 2819557
game: (32500/140785)
numPositions: 2828568
game: (32600/140785)
numPositions: 2837796
game: (32700/140785)
numPositions: 2845958
[2019/06/22 01:29:27]
game: (32800/140785)
numPositions: 2854659
game: (32900/140785)
numPositions: 2863208
game: (33000/140785)
numPositions: 2871744
game: (33100/140785)
numPositions: 2880041
game: (33200/140785)
numPositions: 2888910
game: (33300/140785)
numPositions: 2898286
game: (33400/140785)
numPositions: 2907215
game: (33500/140785)
numPositions: 2915946
game: (33600/140785)
numPositions: 2923902
game: (33700/140785)
numPositions: 2932675
game: (33800/140785)
numPositions: 2940974
game: (33900/140785)
numPositions: 2949485
game: (34000/140785)
numPositions: 2958524
game: (34100/140785)
numPositions: 2967598
game: (34200/140785)
numPositions: 2977339
game: (34300/140785)
numPositions: 2987110
game: (34400/140785)
numPositions: 2997357
[2019/06/22 01:29:28]
game: (34500/140785)
numPositions: 3007022
game: (34600/140785)
numPositions: 3015308
game: (34700/140785)
numPositions: 3024760
game: (34800/140785)
numPositions: 3033823
game: (34900/140785)
numPositions: 3042865
game: (35000/140785)
numPositions: 3051966
game: (35100/140785)
numPositions: 3060246
game: (35200/140785)
numPositions: 3068643
game: (35300/140785)
numPositions: 3076932
game: (35400/140785)
numPositions: 3085742
game: (35500/140785)
numPositions: 3094173
game: (35600/140785)
numPositions: 3102321
game: (35700/140785)
numPositions: 3110974
game: (35800/140785)
numPositions: 3118961
game: (35900/140785)
numPositions: 3127613
game: (36000/140785)
numPositions: 3135578
game: (36100/140785)
numPositions: 3144104
game: (36200/140785)
numPositions: 3152372
game: (36300/140785)
numPositions: 3161039
[2019/06/22 01:29:29]
game: (36400/140785)
numPositions: 3170246
game: (36500/140785)
numPositions: 3178808
game: (36600/140785)
numPositions: 3187243
game: (36700/140785)
numPositions: 3195604
game: (36800/140785)
numPositions: 3204190
game: (36900/140785)
numPositions: 3212806
game: (37000/140785)
numPositions: 3222394
game: (37100/140785)
numPositions: 3231263
game: (37200/140785)
numPositions: 3239834
game: (37300/140785)
numPositions: 3248396
game: (37400/140785)
numPositions: 3256287
game: (37500/140785)
numPositions: 3263924
game: (37600/140785)
numPositions: 3272561
game: (37700/140785)
numPositions: 3280599
game: (37800/140785)
numPositions: 3289330
game: (37900/140785)
numPositions: 3298155
game: (38000/140785)
numPositions: 3306685
game: (38100/140785)
numPositions: 3315197
[2019/06/22 01:29:30]
game: (38200/140785)
numPositions: 3323996
game: (38300/140785)
numPositions: 3333179
game: (38400/140785)
numPositions: 3341871
game: (38500/140785)
numPositions: 3350644
game: (38600/140785)
numPositions: 3359713
game: (38700/140785)
numPositions: 3368864
game: (38800/140785)
numPositions: 3377382
game: (38900/140785)
numPositions: 3387015
game: (39000/140785)
numPositions: 3396062
game: (39100/140785)
numPositions: 3404523
game: (39200/140785)
numPositions: 3412971
game: (39300/140785)
numPositions: 3421260
game: (39400/140785)
numPositions: 3430136
game: (39500/140785)
numPositions: 3438217
game: (39600/140785)
numPositions: 3447111
game: (39700/140785)
numPositions: 3456020
game: (39800/140785)
numPositions: 3465029
game: (39900/140785)
numPositions: 3473820
[2019/06/22 01:29:31]
game: (40000/140785)
numPositions: 3482440
game: (40100/140785)
numPositions: 3491801
game: (40200/140785)
numPositions: 3501175
game: (40300/140785)
numPositions: 3510019
game: (40400/140785)
numPositions: 3517944
game: (40500/140785)
numPositions: 3526520
game: (40600/140785)
numPositions: 3534964
game: (40700/140785)
numPositions: 3543776
game: (40800/140785)
numPositions: 3552128
game: (40900/140785)
numPositions: 3561107
game: (41000/140785)
numPositions: 3569937
game: (41100/140785)
numPositions: 3579099
game: (41200/140785)
numPositions: 3587026
game: (41300/140785)
numPositions: 3595473
game: (41400/140785)
numPositions: 3603694
game: (41500/140785)
numPositions: 3612578
game: (41600/140785)
numPositions: 3621038
game: (41700/140785)
numPositions: 3629714
[2019/06/22 01:29:32]
game: (41800/140785)
numPositions: 3638411
game: (41900/140785)
numPositions: 3646948
game: (42000/140785)
numPositions: 3655772
game: (42100/140785)
numPositions: 3664439
game: (42200/140785)
numPositions: 3672716
game: (42300/140785)
numPositions: 3681997
game: (42400/140785)
numPositions: 3691978
game: (42500/140785)
numPositions: 3701105
game: (42600/140785)
numPositions: 3709343
game: (42700/140785)
numPositions: 3717549
game: (42800/140785)
numPositions: 3725889
game: (42900/140785)
numPositions: 3734634
game: (43000/140785)
numPositions: 3742676
game: (43100/140785)
numPositions: 3751235
game: (43200/140785)
numPositions: 3759691
game: (43300/140785)
numPositions: 3768033
game: (43400/140785)
numPositions: 3776718
game: (43500/140785)
numPositions: 3785272
[2019/06/22 01:29:33]
game: (43600/140785)
numPositions: 3793877
game: (43700/140785)
numPositions: 3802246
game: (43800/140785)
numPositions: 3811589
game: (43900/140785)
numPositions: 3819756
game: (44000/140785)
numPositions: 3828503
game: (44100/140785)
numPositions: 3836173
game: (44200/140785)
numPositions: 3843893
game: (44300/140785)
numPositions: 3851055
game: (44400/140785)
numPositions: 3857906
game: (44500/140785)
numPositions: 3865416
game: (44600/140785)
numPositions: 3874216
game: (44700/140785)
numPositions: 3882455
game: (44800/140785)
numPositions: 3890753
game: (44900/140785)
numPositions: 3899284
game: (45000/140785)
numPositions: 3908185
game: (45100/140785)
numPositions: 3916858
game: (45200/140785)
numPositions: 3925283
game: (45300/140785)
numPositions: 3934625
game: (45400/140785)
numPositions: 3943390
[2019/06/22 01:29:34]
game: (45500/140785)
numPositions: 3952490
game: (45600/140785)
numPositions: 3961184
game: (45700/140785)
numPositions: 3969154
game: (45800/140785)
numPositions: 3977665
game: (45900/140785)
numPositions: 3986346
game: (46000/140785)
numPositions: 3994542
game: (46100/140785)
numPositions: 4002608
game: (46200/140785)
numPositions: 4011820
game: (46300/140785)
numPositions: 4020221
game: (46400/140785)
numPositions: 4028499
game: (46500/140785)
numPositions: 4037066
game: (46600/140785)
numPositions: 4045489
game: (46700/140785)
numPositions: 4053245
game: (46800/140785)
numPositions: 4061971
game: (46900/140785)
numPositions: 4071476
game: (47000/140785)
numPositions: 4080938
game: (47100/140785)
numPositions: 4090573
game: (47200/140785)
numPositions: 4099871
[2019/06/22 01:29:35]
game: (47300/140785)
numPositions: 4108232
game: (47400/140785)
numPositions: 4116467
game: (47500/140785)
numPositions: 4124983
game: (47600/140785)
numPositions: 4133497
game: (47700/140785)
numPositions: 4142191
game: (47800/140785)
numPositions: 4150814
game: (47900/140785)
numPositions: 4159404
game: (48000/140785)
numPositions: 4167978
game: (48100/140785)
numPositions: 4177086
game: (48200/140785)
numPositions: 4185489
game: (48300/140785)
numPositions: 4194630
game: (48400/140785)
numPositions: 4203097
game: (48500/140785)
numPositions: 4211494
game: (48600/140785)
numPositions: 4220154
game: (48700/140785)
numPositions: 4228996
game: (48800/140785)
numPositions: 4237559
game: (48900/140785)
numPositions: 4246323
game: (49000/140785)
numPositions: 4254856
[2019/06/22 01:29:36]
game: (49100/140785)
numPositions: 4262812
game: (49200/140785)
numPositions: 4271148
game: (49300/140785)
numPositions: 4279932
game: (49400/140785)
numPositions: 4288266
game: (49500/140785)
numPositions: 4297276
game: (49600/140785)
numPositions: 4305584
game: (49700/140785)
numPositions: 4314175
game: (49800/140785)
numPositions: 4322813
game: (49900/140785)
numPositions: 4331237
game: (50000/140785)
numPositions: 4340093
game: (50100/140785)
numPositions: 4348677
game: (50200/140785)
numPositions: 4357582
game: (50300/140785)
numPositions: 4366461
game: (50400/140785)
numPositions: 4374497
game: (50500/140785)
numPositions: 4381987
game: (50600/140785)
numPositions: 4389952
game: (50700/140785)
numPositions: 4398070
game: (50800/140785)
numPositions: 4406424
game: (50900/140785)
numPositions: 4414770
[2019/06/22 01:29:37]
game: (51000/140785)
numPositions: 4422406
game: (51100/140785)
numPositions: 4431467
game: (51200/140785)
numPositions: 4441339
game: (51300/140785)
numPositions: 4450459
game: (51400/140785)
numPositions: 4459086
game: (51500/140785)
numPositions: 4466839
game: (51600/140785)
numPositions: 4475509
game: (51700/140785)
numPositions: 4483946
game: (51800/140785)
numPositions: 4492701
game: (51900/140785)
numPositions: 4502036
game: (52000/140785)
numPositions: 4510028
game: (52100/140785)
numPositions: 4517584
game: (52200/140785)
numPositions: 4525599
game: (52300/140785)
numPositions: 4534085
game: (52400/140785)
numPositions: 4542140
game: (52500/140785)
numPositions: 4550595
game: (52600/140785)
numPositions: 4559140
game: (52700/140785)
numPositions: 4567356
[2019/06/22 01:29:38]
game: (52800/140785)
numPositions: 4576363
game: (52900/140785)
numPositions: 4584950
game: (53000/140785)
numPositions: 4592853
game: (53100/140785)
numPositions: 4601823
game: (53200/140785)
numPositions: 4609691
game: (53300/140785)
numPositions: 4617141
game: (53400/140785)
numPositions: 4625015
game: (53500/140785)
numPositions: 4633123
game: (53600/140785)
numPositions: 4641406
game: (53700/140785)
numPositions: 4649251
game: (53800/140785)
numPositions: 4657206
game: (53900/140785)
numPositions: 4665971
game: (54000/140785)
numPositions: 4674282
game: (54100/140785)
numPositions: 4682532
game: (54200/140785)
numPositions: 4691278
game: (54300/140785)
numPositions: 4700003
game: (54400/140785)
numPositions: 4708602
game: (54500/140785)
numPositions: 4717831
game: (54600/140785)
numPositions: 4725995
[2019/06/22 01:29:39]
game: (54700/140785)
numPositions: 4734394
game: (54800/140785)
numPositions: 4743569
game: (54900/140785)
numPositions: 4751768
game: (55000/140785)
numPositions: 4760188
game: (55100/140785)
numPositions: 4768447
game: (55200/140785)
numPositions: 4776666
game: (55300/140785)
numPositions: 4785206
game: (55400/140785)
numPositions: 4793663
game: (55500/140785)
numPositions: 4801835
game: (55600/140785)
numPositions: 4810453
game: (55700/140785)
numPositions: 4819184
game: (55800/140785)
numPositions: 4828335
game: (55900/140785)
numPositions: 4836770
game: (56000/140785)
numPositions: 4844566
game: (56100/140785)
numPositions: 4852719
game: (56200/140785)
numPositions: 4861528
game: (56300/140785)
numPositions: 4871157
game: (56400/140785)
numPositions: 4879824
game: (56500/140785)
numPositions: 4888821
[2019/06/22 01:29:40]
game: (56600/140785)
numPositions: 4896888
game: (56700/140785)
numPositions: 4904790
game: (56800/140785)
numPositions: 4913255
game: (56900/140785)
numPositions: 4922354
game: (57000/140785)
numPositions: 4930822
game: (57100/140785)
numPositions: 4939531
game: (57200/140785)
numPositions: 4948123
game: (57300/140785)
numPositions: 4956931
game: (57400/140785)
numPositions: 4965884
game: (57500/140785)
numPositions: 4974551
game: (57600/140785)
numPositions: 4983243
game: (57700/140785)
numPositions: 4991961
game: (57800/140785)
numPositions: 5000461
game: (57900/140785)
numPositions: 5008468
game: (58000/140785)
numPositions: 5016780
game: (58100/140785)
numPositions: 5024710
game: (58200/140785)
numPositions: 5032665
game: (58300/140785)
numPositions: 5041187
[2019/06/22 01:29:41]
game: (58400/140785)
numPositions: 5048979
game: (58500/140785)
numPositions: 5057480
game: (58600/140785)
numPositions: 5065790
game: (58700/140785)
numPositions: 5074290
game: (58800/140785)
numPositions: 5082839
game: (58900/140785)
numPositions: 5091522
game: (59000/140785)
numPositions: 5099920
game: (59100/140785)
numPositions: 5108820
game: (59200/140785)
numPositions: 5117271
game: (59300/140785)
numPositions: 5125282
game: (59400/140785)
numPositions: 5133563
game: (59500/140785)
numPositions: 5142086
game: (59600/140785)
numPositions: 5150650
game: (59700/140785)
numPositions: 5159178
game: (59800/140785)
numPositions: 5167163
game: (59900/140785)
numPositions: 5176451
game: (60000/140785)
numPositions: 5185587
game: (60100/140785)
numPositions: 5194895
[2019/06/22 01:29:42]
game: (60200/140785)
numPositions: 5202784
game: (60300/140785)
numPositions: 5211363
game: (60400/140785)
numPositions: 5219462
game: (60500/140785)
numPositions: 5227370
game: (60600/140785)
numPositions: 5236114
game: (60700/140785)
numPositions: 5244499
game: (60800/140785)
numPositions: 5252673
game: (60900/140785)
numPositions: 5260615
game: (61000/140785)
numPositions: 5269189
game: (61100/140785)
numPositions: 5277787
game: (61200/140785)
numPositions: 5286678
game: (61300/140785)
numPositions: 5294682
game: (61400/140785)
numPositions: 5303088
game: (61500/140785)
numPositions: 5311133
game: (61600/140785)
numPositions: 5319824
game: (61700/140785)
numPositions: 5328129
game: (61800/140785)
numPositions: 5335739
game: (61900/140785)
numPositions: 5343272
game: (62000/140785)
numPositions: 5350651
[2019/06/22 01:29:43]
game: (62100/140785)
numPositions: 5357910
game: (62200/140785)
numPositions: 5365980
game: (62300/140785)
numPositions: 5373702
game: (62400/140785)
numPositions: 5382354
game: (62500/140785)
numPositions: 5391506
game: (62600/140785)
numPositions: 5400257
game: (62700/140785)
numPositions: 5409282
game: (62800/140785)
numPositions: 5417944
game: (62900/140785)
numPositions: 5426389
game: (63000/140785)
numPositions: 5434042
game: (63100/140785)
numPositions: 5442470
game: (63200/140785)
numPositions: 5450587
game: (63300/140785)
numPositions: 5459008
game: (63400/140785)
numPositions: 5466949
game: (63500/140785)
numPositions: 5475135
game: (63600/140785)
numPositions: 5483170
game: (63700/140785)
numPositions: 5491458
game: (63800/140785)
numPositions: 5499912
game: (63900/140785)
numPositions: 5507853
[2019/06/22 01:29:44]
game: (64000/140785)
numPositions: 5516092
game: (64100/140785)
numPositions: 5524487
game: (64200/140785)
numPositions: 5532159
game: (64300/140785)
numPositions: 5540439
game: (64400/140785)
numPositions: 5548763
game: (64500/140785)
numPositions: 5557140
game: (64600/140785)
numPositions: 5565777
game: (64700/140785)
numPositions: 5574483
game: (64800/140785)
numPositions: 5582883
game: (64900/140785)
numPositions: 5590577
game: (65000/140785)
numPositions: 5598446
game: (65100/140785)
numPositions: 5605718
game: (65200/140785)
numPositions: 5614158
game: (65300/140785)
numPositions: 5622982
game: (65400/140785)
numPositions: 5632057
game: (65500/140785)
numPositions: 5639475
game: (65600/140785)
numPositions: 5646882
game: (65700/140785)
numPositions: 5655603
game: (65800/140785)
numPositions: 5664186
[2019/06/22 01:29:45]
game: (65900/140785)
numPositions: 5672442
game: (66000/140785)
numPositions: 5680295
game: (66100/140785)
numPositions: 5689080
game: (66200/140785)
numPositions: 5697212
game: (66300/140785)
numPositions: 5705536
game: (66400/140785)
numPositions: 5714102
game: (66500/140785)
numPositions: 5722290
game: (66600/140785)
numPositions: 5730760
game: (66700/140785)
numPositions: 5740372
game: (66800/140785)
numPositions: 5749364
game: (66900/140785)
numPositions: 5758044
game: (67000/140785)
numPositions: 5766247
game: (67100/140785)
numPositions: 5775295
game: (67200/140785)
numPositions: 5783636
game: (67300/140785)
numPositions: 5791933
game: (67400/140785)
numPositions: 5800989
game: (67500/140785)
numPositions: 5809126
game: (67600/140785)
numPositions: 5817480
[2019/06/22 01:29:46]
game: (67700/140785)
numPositions: 5826468
game: (67800/140785)
numPositions: 5834877
game: (67900/140785)
numPositions: 5843651
game: (68000/140785)
numPositions: 5851517
game: (68100/140785)
numPositions: 5860159
game: (68200/140785)
numPositions: 5868601
game: (68300/140785)
numPositions: 5877342
game: (68400/140785)
numPositions: 5885521
game: (68500/140785)
numPositions: 5893652
game: (68600/140785)
numPositions: 5901941
game: (68700/140785)
numPositions: 5909974
game: (68800/140785)
numPositions: 5917986
game: (68900/140785)
numPositions: 5925971
game: (69000/140785)
numPositions: 5933977
game: (69100/140785)
numPositions: 5942114
game: (69200/140785)
numPositions: 5950485
game: (69300/140785)
numPositions: 5959292
game: (69400/140785)
numPositions: 5967831
game: (69500/140785)
numPositions: 5975950
[2019/06/22 01:29:47]
game: (69600/140785)
numPositions: 5984297
game: (69700/140785)
numPositions: 5993265
game: (69800/140785)
numPositions: 6002003
game: (69900/140785)
numPositions: 6010471
game: (70000/140785)
numPositions: 6017806
game: (70100/140785)
numPositions: 6025693
game: (70200/140785)
numPositions: 6033078
game: (70300/140785)
numPositions: 6040734
game: (70400/140785)
numPositions: 6048744
game: (70500/140785)
numPositions: 6056210
game: (70600/140785)
numPositions: 6063826
game: (70700/140785)
numPositions: 6072432
game: (70800/140785)
numPositions: 6080785
game: (70900/140785)
numPositions: 6089149
game: (71000/140785)
numPositions: 6097210
game: (71100/140785)
numPositions: 6105560
game: (71200/140785)
numPositions: 6113594
game: (71300/140785)
numPositions: 6121656
game: (71400/140785)
numPositions: 6129806
[2019/06/22 01:29:48]
game: (71500/140785)
numPositions: 6137584
game: (71600/140785)
numPositions: 6145456
game: (71700/140785)
numPositions: 6153357
game: (71800/140785)
numPositions: 6161621
game: (71900/140785)
numPositions: 6170541
game: (72000/140785)
numPositions: 6178822
game: (72100/140785)
numPositions: 6186537
game: (72200/140785)
numPositions: 6194718
game: (72300/140785)
numPositions: 6202415
game: (72400/140785)
numPositions: 6210786
game: (72500/140785)
numPositions: 6219778
game: (72600/140785)
numPositions: 6227772
game: (72700/140785)
numPositions: 6236274
game: (72800/140785)
numPositions: 6244596
game: (72900/140785)
numPositions: 6252360
game: (73000/140785)
numPositions: 6260486
game: (73100/140785)
numPositions: 6268859
[2019/06/22 01:29:49]
game: (73200/140785)
numPositions: 6277211
game: (73300/140785)
numPositions: 6285500
game: (73400/140785)
numPositions: 6294234
game: (73500/140785)
numPositions: 6302792
game: (73600/140785)
numPositions: 6311625
game: (73700/140785)
numPositions: 6320267
game: (73800/140785)
numPositions: 6328045
game: (73900/140785)
numPositions: 6335689
game: (74000/140785)
numPositions: 6343682
game: (74100/140785)
numPositions: 6351759
game: (74200/140785)
numPositions: 6359635
game: (74300/140785)
numPositions: 6367995
game: (74400/140785)
numPositions: 6376130
game: (74500/140785)
numPositions: 6384489
game: (74600/140785)
numPositions: 6392838
game: (74700/140785)
numPositions: 6401242
game: (74800/140785)
numPositions: 6409950
game: (74900/140785)
numPositions: 6418180
game: (75000/140785)
numPositions: 6426354
[2019/06/22 01:29:50]
game: (75100/140785)
numPositions: 6435087
game: (75200/140785)
numPositions: 6443552
game: (75300/140785)
numPositions: 6451644
game: (75400/140785)
numPositions: 6460249
game: (75500/140785)
numPositions: 6469276
game: (75600/140785)
numPositions: 6477751
game: (75700/140785)
numPositions: 6486309
game: (75800/140785)
numPositions: 6494892
game: (75900/140785)
numPositions: 6502868
game: (76000/140785)
numPositions: 6510942
game: (76100/140785)
numPositions: 6519521
game: (76200/140785)
numPositions: 6528155
game: (76300/140785)
numPositions: 6536957
game: (76400/140785)
numPositions: 6545707
game: (76500/140785)
numPositions: 6553931
game: (76600/140785)
numPositions: 6562761
game: (76700/140785)
numPositions: 6571541
game: (76800/140785)
numPositions: 6579656
game: (76900/140785)
numPositions: 6588144
[2019/06/22 01:29:51]
game: (77000/140785)
numPositions: 6596472
game: (77100/140785)
numPositions: 6605173
game: (77200/140785)
numPositions: 6613383
game: (77300/140785)
numPositions: 6621365
game: (77400/140785)
numPositions: 6629797
game: (77500/140785)
numPositions: 6638448
game: (77600/140785)
numPositions: 6646881
game: (77700/140785)
numPositions: 6655051
game: (77800/140785)
numPositions: 6663950
game: (77900/140785)
numPositions: 6671950
game: (78000/140785)
numPositions: 6679618
game: (78100/140785)
numPositions: 6688263
game: (78200/140785)
numPositions: 6696458
game: (78300/140785)
numPositions: 6704615
game: (78400/140785)
numPositions: 6712464
game: (78500/140785)
numPositions: 6721507
game: (78600/140785)
numPositions: 6729450
game: (78700/140785)
numPositions: 6736737
[2019/06/22 01:29:52]
game: (78800/140785)
numPositions: 6744836
game: (78900/140785)
numPositions: 6753111
game: (79000/140785)
numPositions: 6760862
game: (79100/140785)
numPositions: 6768595
game: (79200/140785)
numPositions: 6777419
game: (79300/140785)
numPositions: 6786034
game: (79400/140785)
numPositions: 6794050
game: (79500/140785)
numPositions: 6802149
game: (79600/140785)
numPositions: 6810192
game: (79700/140785)
numPositions: 6817669
game: (79800/140785)
numPositions: 6826063
game: (79900/140785)
numPositions: 6834143
game: (80000/140785)
numPositions: 6842437
game: (80100/140785)
numPositions: 6850959
game: (80200/140785)
numPositions: 6859562
game: (80300/140785)
numPositions: 6867506
game: (80400/140785)
numPositions: 6875259
game: (80500/140785)
numPositions: 6883625
game: (80600/140785)
numPositions: 6891738
[2019/06/22 01:29:53]
game: (80700/140785)
numPositions: 6899655
game: (80800/140785)
numPositions: 6907602
game: (80900/140785)
numPositions: 6915629
game: (81000/140785)
numPositions: 6925284
game: (81100/140785)
numPositions: 6934160
game: (81200/140785)
numPositions: 6943199
game: (81300/140785)
numPositions: 6951748
game: (81400/140785)
numPositions: 6960511
game: (81500/140785)
numPositions: 6968657
game: (81600/140785)
numPositions: 6977177
game: (81700/140785)
numPositions: 6984881
game: (81800/140785)
numPositions: 6992414
game: (81900/140785)
numPositions: 7001213
game: (82000/140785)
numPositions: 7009306
game: (82100/140785)
numPositions: 7017252
game: (82200/140785)
numPositions: 7025205
game: (82300/140785)
numPositions: 7032623
game: (82400/140785)
numPositions: 7040330
game: (82500/140785)
numPositions: 7047641
[2019/06/22 01:29:54]
game: (82600/140785)
numPositions: 7054905
game: (82700/140785)
numPositions: 7063288
game: (82800/140785)
numPositions: 7071326
game: (82900/140785)
numPositions: 7079209
game: (83000/140785)
numPositions: 7087551
game: (83100/140785)
numPositions: 7096364
game: (83200/140785)
numPositions: 7104256
game: (83300/140785)
numPositions: 7111779
game: (83400/140785)
numPositions: 7119674
game: (83500/140785)
numPositions: 7127376
game: (83600/140785)
numPositions: 7135014
game: (83700/140785)
numPositions: 7142496
game: (83800/140785)
numPositions: 7150465
game: (83900/140785)
numPositions: 7158593
game: (84000/140785)
numPositions: 7166785
game: (84100/140785)
numPositions: 7175067
game: (84200/140785)
numPositions: 7183903
game: (84300/140785)
numPositions: 7192634
game: (84400/140785)
numPositions: 7200855
[2019/06/22 01:29:55]
game: (84500/140785)
numPositions: 7208703
game: (84600/140785)
numPositions: 7216163
game: (84700/140785)
numPositions: 7223618
game: (84800/140785)
numPositions: 7232139
game: (84900/140785)
numPositions: 7240205
game: (85000/140785)
numPositions: 7248456
game: (85100/140785)
numPositions: 7256725
game: (85200/140785)
numPositions: 7265028
game: (85300/140785)
numPositions: 7271982
game: (85400/140785)
numPositions: 7280343
game: (85500/140785)
numPositions: 7287283
game: (85600/140785)
numPositions: 7295479
game: (85700/140785)
numPositions: 7303371
game: (85800/140785)
numPositions: 7311143
game: (85900/140785)
numPositions: 7319057
game: (86000/140785)
numPositions: 7327243
game: (86100/140785)
numPositions: 7334908
game: (86200/140785)
numPositions: 7343014
game: (86300/140785)
numPositions: 7351309
game: (86400/140785)
numPositions: 7359804
[2019/06/22 01:29:56]
game: (86500/140785)
numPositions: 7367376
game: (86600/140785)
numPositions: 7376007
game: (86700/140785)
numPositions: 7384402
game: (86800/140785)
numPositions: 7392237
game: (86900/140785)
numPositions: 7399964
game: (87000/140785)
numPositions: 7407808
game: (87100/140785)
numPositions: 7416312
game: (87200/140785)
numPositions: 7425113
game: (87300/140785)
numPositions: 7433760
game: (87400/140785)
numPositions: 7441780
game: (87500/140785)
numPositions: 7449335
game: (87600/140785)
numPositions: 7457269
game: (87700/140785)
numPositions: 7465484
game: (87800/140785)
numPositions: 7473451
game: (87900/140785)
numPositions: 7480554
game: (88000/140785)
numPositions: 7488363
game: (88100/140785)
numPositions: 7495447
game: (88200/140785)
numPositions: 7502992
[2019/06/22 01:29:57]
game: (88300/140785)
numPositions: 7511599
game: (88400/140785)
numPositions: 7520068
game: (88500/140785)
numPositions: 7527815
game: (88600/140785)
numPositions: 7535225
game: (88700/140785)
numPositions: 7542941
game: (88800/140785)
numPositions: 7551076
game: (88900/140785)
numPositions: 7559263
game: (89000/140785)
numPositions: 7568547
game: (89100/140785)
numPositions: 7577073
game: (89200/140785)
numPositions: 7584776
game: (89300/140785)
numPositions: 7592882
game: (89400/140785)
numPositions: 7601660
game: (89500/140785)
numPositions: 7609962
game: (89600/140785)
numPositions: 7618076
game: (89700/140785)
numPositions: 7627312
game: (89800/140785)
numPositions: 7635664
game: (89900/140785)
numPositions: 7643105
game: (90000/140785)
numPositions: 7651539
game: (90100/140785)
numPositions: 7660104
[2019/06/22 01:29:58]
game: (90200/140785)
numPositions: 7668702
game: (90300/140785)
numPositions: 7676797
game: (90400/140785)
numPositions: 7684809
game: (90500/140785)
numPositions: 7692641
game: (90600/140785)
numPositions: 7700481
game: (90700/140785)
numPositions: 7708617
game: (90800/140785)
numPositions: 7716380
game: (90900/140785)
numPositions: 7724654
game: (91000/140785)
numPositions: 7732276
game: (91100/140785)
numPositions: 7740622
game: (91200/140785)
numPositions: 7748665
game: (91300/140785)
numPositions: 7756618
game: (91400/140785)
numPositions: 7764569
game: (91500/140785)
numPositions: 7771864
game: (91600/140785)
numPositions: 7779537
game: (91700/140785)
numPositions: 7786900
game: (91800/140785)
numPositions: 7794468
game: (91900/140785)
numPositions: 7801653
game: (92000/140785)
numPositions: 7809525
game: (92100/140785)
numPositions: 7816721
[2019/06/22 01:29:59]
game: (92200/140785)
numPositions: 7824358
game: (92300/140785)
numPositions: 7832626
game: (92400/140785)
numPositions: 7840347
game: (92500/140785)
numPositions: 7848042
game: (92600/140785)
numPositions: 7856028
game: (92700/140785)
numPositions: 7863706
game: (92800/140785)
numPositions: 7871805
game: (92900/140785)
numPositions: 7880676
game: (93000/140785)
numPositions: 7888743
game: (93100/140785)
numPositions: 7896614
game: (93200/140785)
numPositions: 7904400
game: (93300/140785)
numPositions: 7912526
game: (93400/140785)
numPositions: 7920744
game: (93500/140785)
numPositions: 7928868
game: (93600/140785)
numPositions: 7936534
game: (93700/140785)
numPositions: 7944985
game: (93800/140785)
numPositions: 7952784
game: (93900/140785)
numPositions: 7960714
game: (94000/140785)
numPositions: 7968456
[2019/06/22 01:30:00]
game: (94100/140785)
numPositions: 7976537
game: (94200/140785)
numPositions: 7983989
game: (94300/140785)
numPositions: 7991998
game: (94400/140785)
numPositions: 8000141
game: (94500/140785)
numPositions: 8008775
game: (94600/140785)
numPositions: 8016764
game: (94700/140785)
numPositions: 8024407
game: (94800/140785)
numPositions: 8032326
game: (94900/140785)
numPositions: 8040377
game: (95000/140785)
numPositions: 8048171
game: (95100/140785)
numPositions: 8056048
game: (95200/140785)
numPositions: 8064045
game: (95300/140785)
numPositions: 8072355
game: (95400/140785)
numPositions: 8079577
game: (95500/140785)
numPositions: 8087573
game: (95600/140785)
numPositions: 8095783
game: (95700/140785)
numPositions: 8103785
game: (95800/140785)
numPositions: 8111687
game: (95900/140785)
numPositions: 8117959
game: (96000/140785)
numPositions: 8125931
[2019/06/22 01:30:01]
game: (96100/140785)
numPositions: 8134746
game: (96200/140785)
numPositions: 8142556
game: (96300/140785)
numPositions: 8151083
game: (96400/140785)
numPositions: 8159000
game: (96500/140785)
numPositions: 8166400
game: (96600/140785)
numPositions: 8174380
game: (96700/140785)
numPositions: 8182515
game: (96800/140785)
numPositions: 8189582
game: (96900/140785)
numPositions: 8197171
game: (97000/140785)
numPositions: 8205234
game: (97100/140785)
numPositions: 8213083
game: (97200/140785)
numPositions: 8221165
game: (97300/140785)
numPositions: 8229641
game: (97400/140785)
numPositions: 8237434
game: (97500/140785)
numPositions: 8245542
game: (97600/140785)
numPositions: 8252965
game: (97700/140785)
numPositions: 8260696
game: (97800/140785)
numPositions: 8268842
game: (97900/140785)
numPositions: 8276129
[2019/06/22 01:30:02]
game: (98000/140785)
numPositions: 8283556
game: (98100/140785)
numPositions: 8291607
game: (98200/140785)
numPositions: 8298812
game: (98300/140785)
numPositions: 8307005
game: (98400/140785)
numPositions: 8314881
game: (98500/140785)
numPositions: 8323162
game: (98600/140785)
numPositions: 8331457
game: (98700/140785)
numPositions: 8339305
game: (98800/140785)
numPositions: 8347128
game: (98900/140785)
numPositions: 8354713
game: (99000/140785)
numPositions: 8363536
game: (99100/140785)
numPositions: 8371991
game: (99200/140785)
numPositions: 8380085
game: (99300/140785)
numPositions: 8388049
game: (99400/140785)
numPositions: 8395667
game: (99500/140785)
numPositions: 8403134
game: (99600/140785)
numPositions: 8410973
game: (99700/140785)
numPositions: 8418855
game: (99800/140785)
numPositions: 8427156
game: (99900/140785)
numPositions: 8434663
[2019/06/22 01:30:03]
game: (100000/140785)
numPositions: 8443546
game: (100100/140785)
numPositions: 8451596
game: (100200/140785)
numPositions: 8459335
game: (100300/140785)
numPositions: 8466509
game: (100400/140785)
numPositions: 8474686
game: (100500/140785)
numPositions: 8482038
game: (100600/140785)
numPositions: 8490872
game: (100700/140785)
numPositions: 8499327
game: (100800/140785)
numPositions: 8507633
game: (100900/140785)
numPositions: 8515602
game: (101000/140785)
numPositions: 8523370
game: (101100/140785)
numPositions: 8532004
game: (101200/140785)
numPositions: 8539778
game: (101300/140785)
numPositions: 8547817
game: (101400/140785)
numPositions: 8555957
game: (101500/140785)
numPositions: 8563937
game: (101600/140785)
numPositions: 8572434
game: (101700/140785)
numPositions: 8580717
game: (101800/140785)
numPositions: 8588500
[2019/06/22 01:30:04]
game: (101900/140785)
numPositions: 8597202
game: (102000/140785)
numPositions: 8605785
game: (102100/140785)
numPositions: 8613453
game: (102200/140785)
numPositions: 8621251
game: (102300/140785)
numPositions: 8627979
game: (102400/140785)
numPositions: 8635865
game: (102500/140785)
numPositions: 8643645
game: (102600/140785)
numPositions: 8651770
game: (102700/140785)
numPositions: 8659138
game: (102800/140785)
numPositions: 8666614
game: (102900/140785)
numPositions: 8674752
game: (103000/140785)
numPositions: 8682909
game: (103100/140785)
numPositions: 8691274
game: (103200/140785)
numPositions: 8699962
game: (103300/140785)
numPositions: 8706634
game: (103400/140785)
numPositions: 8714585
game: (103500/140785)
numPositions: 8722347
game: (103600/140785)
numPositions: 8729708
game: (103700/140785)
numPositions: 8736819
game: (103800/140785)
numPositions: 8744551
[2019/06/22 01:30:05]
game: (103900/140785)
numPositions: 8751988
game: (104000/140785)
numPositions: 8759230
game: (104100/140785)
numPositions: 8767353
game: (104200/140785)
numPositions: 8775909
game: (104300/140785)
numPositions: 8785232
game: (104400/140785)
numPositions: 8794328
game: (104500/140785)
numPositions: 8802004
game: (104600/140785)
numPositions: 8811197
game: (104700/140785)
numPositions: 8818076
game: (104800/140785)
numPositions: 8826023
game: (104900/140785)
numPositions: 8834596
game: (105000/140785)
numPositions: 8843687
game: (105100/140785)
numPositions: 8851111
game: (105200/140785)
numPositions: 8859370
game: (105300/140785)
numPositions: 8866585
game: (105400/140785)
numPositions: 8874306
game: (105500/140785)
numPositions: 8881894
game: (105600/140785)
numPositions: 8890506
game: (105700/140785)
numPositions: 8899284
[2019/06/22 01:30:06]
game: (105800/140785)
numPositions: 8906638
game: (105900/140785)
numPositions: 8914464
game: (106000/140785)
numPositions: 8922072
game: (106100/140785)
numPositions: 8929779
game: (106200/140785)
numPositions: 8937729
game: (106300/140785)
numPositions: 8946039
game: (106400/140785)
numPositions: 8953830
game: (106500/140785)
numPositions: 8961638
game: (106600/140785)
numPositions: 8970107
game: (106700/140785)
numPositions: 8978084
game: (106800/140785)
numPositions: 8986289
game: (106900/140785)
numPositions: 8993774
game: (107000/140785)
numPositions: 9001641
game: (107100/140785)
numPositions: 9008849
game: (107200/140785)
numPositions: 9017329
game: (107300/140785)
numPositions: 9025275
game: (107400/140785)
numPositions: 9032768
game: (107500/140785)
numPositions: 9040283
game: (107600/140785)
numPositions: 9048349
[2019/06/22 01:30:07]
game: (107700/140785)
numPositions: 9056111
game: (107800/140785)
numPositions: 9064368
game: (107900/140785)
numPositions: 9072558
game: (108000/140785)
numPositions: 9081262
game: (108100/140785)
numPositions: 9088815
game: (108200/140785)
numPositions: 9096714
game: (108300/140785)
numPositions: 9104455
game: (108400/140785)
numPositions: 9112031
game: (108500/140785)
numPositions: 9119651
game: (108600/140785)
numPositions: 9127327
game: (108700/140785)
numPositions: 9134711
game: (108800/140785)
numPositions: 9142534
game: (108900/140785)
numPositions: 9149332
game: (109000/140785)
numPositions: 9157944
game: (109100/140785)
numPositions: 9165109
game: (109200/140785)
numPositions: 9172074
game: (109300/140785)
numPositions: 9179036
game: (109400/140785)
numPositions: 9187256
game: (109500/140785)
numPositions: 9194779
game: (109600/140785)
numPositions: 9203172
[2019/06/22 01:30:08]
game: (109700/140785)
numPositions: 9210441
game: (109800/140785)
numPositions: 9218192
game: (109900/140785)
numPositions: 9226638
game: (110000/140785)
numPositions: 9234988
game: (110100/140785)
numPositions: 9243039
game: (110200/140785)
numPositions: 9251340
game: (110300/140785)
numPositions: 9259137
game: (110400/140785)
numPositions: 9266811
game: (110500/140785)
numPositions: 9275036
game: (110600/140785)
numPositions: 9284093
game: (110700/140785)
numPositions: 9293143
game: (110800/140785)
numPositions: 9302137
game: (110900/140785)
numPositions: 9310150
game: (111000/140785)
numPositions: 9318110
game: (111100/140785)
numPositions: 9326154
game: (111200/140785)
numPositions: 9333882
game: (111300/140785)
numPositions: 9341600
game: (111400/140785)
numPositions: 9350111
game: (111500/140785)
numPositions: 9358089
[2019/06/22 01:30:09]
game: (111600/140785)
numPositions: 9366111
game: (111700/140785)
numPositions: 9373994
game: (111800/140785)
numPositions: 9381006
game: (111900/140785)
numPositions: 9389015
game: (112000/140785)
numPositions: 9395883
game: (112100/140785)
numPositions: 9404320
game: (112200/140785)
numPositions: 9412177
game: (112300/140785)
numPositions: 9419332
game: (112400/140785)
numPositions: 9427308
game: (112500/140785)
numPositions: 9434917
game: (112600/140785)
numPositions: 9442018
game: (112700/140785)
numPositions: 9449662
game: (112800/140785)
numPositions: 9457828
game: (112900/140785)
numPositions: 9464755
game: (113000/140785)
numPositions: 9472902
game: (113100/140785)
numPositions: 9480747
game: (113200/140785)
numPositions: 9488741
game: (113300/140785)
numPositions: 9496611
game: (113400/140785)
numPositions: 9504717
game: (113500/140785)
numPositions: 9512209
[2019/06/22 01:30:10]
game: (113600/140785)
numPositions: 9520420
game: (113700/140785)
numPositions: 9528239
game: (113800/140785)
numPositions: 9536074
game: (113900/140785)
numPositions: 9543877
game: (114000/140785)
numPositions: 9551500
game: (114100/140785)
numPositions: 9558711
game: (114200/140785)
numPositions: 9566063
game: (114300/140785)
numPositions: 9574305
game: (114400/140785)
numPositions: 9582792
game: (114500/140785)
numPositions: 9590986
game: (114600/140785)
numPositions: 9599272
game: (114700/140785)
numPositions: 9607730
game: (114800/140785)
numPositions: 9615688
game: (114900/140785)
numPositions: 9623994
game: (115000/140785)
numPositions: 9631406
game: (115100/140785)
numPositions: 9639517
game: (115200/140785)
numPositions: 9646428
game: (115300/140785)
numPositions: 9653611
game: (115400/140785)
numPositions: 9660802
game: (115500/140785)
numPositions: 9668293
[2019/06/22 01:30:11]
game: (115600/140785)
numPositions: 9676304
game: (115700/140785)
numPositions: 9684564
game: (115800/140785)
numPositions: 9691861
game: (115900/140785)
numPositions: 9699756
game: (116000/140785)
numPositions: 9707702
game: (116100/140785)
numPositions: 9716124
game: (116200/140785)
numPositions: 9725052
game: (116300/140785)
numPositions: 9732726
game: (116400/140785)
numPositions: 9741385
game: (116500/140785)
numPositions: 9748382
game: (116600/140785)
numPositions: 9756621
game: (116700/140785)
numPositions: 9764418
game: (116800/140785)
numPositions: 9772697
game: (116900/140785)
numPositions: 9780009
game: (117000/140785)
numPositions: 9788031
game: (117100/140785)
numPositions: 9795972
game: (117200/140785)
numPositions: 9803968
game: (117300/140785)
numPositions: 9811773
game: (117400/140785)
numPositions: 9819089
[2019/06/22 01:30:12]
game: (117500/140785)
numPositions: 9828267
game: (117600/140785)
numPositions: 9835786
game: (117700/140785)
numPositions: 9843808
game: (117800/140785)
numPositions: 9851215
game: (117900/140785)
numPositions: 9859050
game: (118000/140785)
numPositions: 9866482
game: (118100/140785)
numPositions: 9874551
game: (118200/140785)
numPositions: 9882715
game: (118300/140785)
numPositions: 9890993
game: (118400/140785)
numPositions: 9898627
game: (118500/140785)
numPositions: 9906199
game: (118600/140785)
numPositions: 9914129
game: (118700/140785)
numPositions: 9921460
game: (118800/140785)
numPositions: 9928957
game: (118900/140785)
numPositions: 9936934
game: (119000/140785)
numPositions: 9944780
game: (119100/140785)
numPositions: 9952415
game: (119200/140785)
numPositions: 9959795
game: (119300/140785)
numPositions: 9966764
[2019/06/22 01:30:13]
game: (119400/140785)
numPositions: 9974744
game: (119500/140785)
numPositions: 9982824
game: (119600/140785)
numPositions: 9990682
game: (119700/140785)
numPositions: 9999025
game: (119800/140785)
numPositions: 10007073
game: (119900/140785)
numPositions: 10014770
game: (120000/140785)
numPositions: 10022876
game: (120100/140785)
numPositions: 10030963
game: (120200/140785)
numPositions: 10039221
game: (120300/140785)
numPositions: 10047264
game: (120400/140785)
numPositions: 10055241
game: (120500/140785)
numPositions: 10063538
game: (120600/140785)
numPositions: 10071428
game: (120700/140785)
numPositions: 10078762
game: (120800/140785)
numPositions: 10086642
game: (120900/140785)
numPositions: 10094259
game: (121000/140785)
numPositions: 10101606
game: (121100/140785)
numPositions: 10109354
game: (121200/140785)
numPositions: 10117285
game: (121300/140785)
numPositions: 10125571
[2019/06/22 01:30:14]
game: (121400/140785)
numPositions: 10132769
game: (121500/140785)
numPositions: 10140682
game: (121600/140785)
numPositions: 10148071
game: (121700/140785)
numPositions: 10156527
game: (121800/140785)
numPositions: 10164288
game: (121900/140785)
numPositions: 10171803
game: (122000/140785)
numPositions: 10178803
game: (122100/140785)
numPositions: 10186992
game: (122200/140785)
numPositions: 10195667
game: (122300/140785)
numPositions: 10203918
game: (122400/140785)
numPositions: 10212287
game: (122500/140785)
numPositions: 10218848
game: (122600/140785)
numPositions: 10226399
game: (122700/140785)
numPositions: 10234528
game: (122800/140785)
numPositions: 10242360
game: (122900/140785)
numPositions: 10249846
game: (123000/140785)
numPositions: 10257465
game: (123100/140785)
numPositions: 10265024
game: (123200/140785)
numPositions: 10272619
game: (123300/140785)
numPositions: 10280641
[2019/06/22 01:30:15]
game: (123400/140785)
numPositions: 10288379
game: (123500/140785)
numPositions: 10296116
game: (123600/140785)
numPositions: 10303507
game: (123700/140785)
numPositions: 10311344
game: (123800/140785)
numPositions: 10319165
game: (123900/140785)
numPositions: 10326937
game: (124000/140785)
numPositions: 10335295
game: (124100/140785)
numPositions: 10343614
game: (124200/140785)
numPositions: 10351299
game: (124300/140785)
numPositions: 10359082
game: (124400/140785)
numPositions: 10366685
game: (124500/140785)
numPositions: 10374532
game: (124600/140785)
numPositions: 10382371
game: (124700/140785)
numPositions: 10390264
game: (124800/140785)
numPositions: 10398144
game: (124900/140785)
numPositions: 10406622
game: (125000/140785)
numPositions: 10414708
game: (125100/140785)
numPositions: 10422339
game: (125200/140785)
numPositions: 10430548
[2019/06/22 01:30:16]
game: (125300/140785)
numPositions: 10438732
game: (125400/140785)
numPositions: 10447252
game: (125500/140785)
numPositions: 10455398
game: (125600/140785)
numPositions: 10463217
game: (125700/140785)
numPositions: 10471863
game: (125800/140785)
numPositions: 10480255
game: (125900/140785)
numPositions: 10488561
game: (126000/140785)
numPositions: 10496622
game: (126100/140785)
numPositions: 10503941
game: (126200/140785)
numPositions: 10511576
game: (126300/140785)
numPositions: 10519897
game: (126400/140785)
numPositions: 10527882
game: (126500/140785)
numPositions: 10536123
game: (126600/140785)
numPositions: 10544372
game: (126700/140785)
numPositions: 10552005
game: (126800/140785)
numPositions: 10560170
game: (126900/140785)
numPositions: 10567889
game: (127000/140785)
numPositions: 10576196
game: (127100/140785)
numPositions: 10583677
game: (127200/140785)
numPositions: 10591121
[2019/06/22 01:30:17]
game: (127300/140785)
numPositions: 10599172
game: (127400/140785)
numPositions: 10607870
game: (127500/140785)
numPositions: 10616750
game: (127600/140785)
numPositions: 10624549
game: (127700/140785)
numPositions: 10632060
game: (127800/140785)
numPositions: 10639727
game: (127900/140785)
numPositions: 10647535
game: (128000/140785)
numPositions: 10655823
game: (128100/140785)
numPositions: 10663967
game: (128200/140785)
numPositions: 10672103
game: (128300/140785)
numPositions: 10680314
game: (128400/140785)
numPositions: 10687231
game: (128500/140785)
numPositions: 10695310
game: (128600/140785)
numPositions: 10703802
game: (128700/140785)
numPositions: 10711311
game: (128800/140785)
numPositions: 10718871
game: (128900/140785)
numPositions: 10727380
game: (129000/140785)
numPositions: 10735554
[2019/06/22 01:30:18]
game: (129100/140785)
numPositions: 10743119
game: (129200/140785)
numPositions: 10750715
game: (129300/140785)
numPositions: 10757874
game: (129400/140785)
numPositions: 10765224
game: (129500/140785)
numPositions: 10773593
game: (129600/140785)
numPositions: 10782100
game: (129700/140785)
numPositions: 10789778
game: (129800/140785)
numPositions: 10797971
game: (129900/140785)
numPositions: 10805796
game: (130000/140785)
numPositions: 10813790
game: (130100/140785)
numPositions: 10821260
game: (130200/140785)
numPositions: 10828566
game: (130300/140785)
numPositions: 10836829
game: (130400/140785)
numPositions: 10844830
game: (130500/140785)
numPositions: 10853290
game: (130600/140785)
numPositions: 10860752
game: (130700/140785)
numPositions: 10868732
game: (130800/140785)
numPositions: 10876432
game: (130900/140785)
numPositions: 10883932
game: (131000/140785)
numPositions: 10891561
[2019/06/22 01:30:19]
game: (131100/140785)
numPositions: 10899344
game: (131200/140785)
numPositions: 10906570
game: (131300/140785)
numPositions: 10914968
game: (131400/140785)
numPositions: 10923038
game: (131500/140785)
numPositions: 10930544
game: (131600/140785)
numPositions: 10938929
game: (131700/140785)
numPositions: 10945996
game: (131800/140785)
numPositions: 10953242
game: (131900/140785)
numPositions: 10961021
game: (132000/140785)
numPositions: 10969241
game: (132100/140785)
numPositions: 10977613
game: (132200/140785)
numPositions: 10985346
game: (132300/140785)
numPositions: 10992749
game: (132400/140785)
numPositions: 11000473
game: (132500/140785)
numPositions: 11008079
game: (132600/140785)
numPositions: 11016135
game: (132700/140785)
numPositions: 11024200
game: (132800/140785)
numPositions: 11031725
game: (132900/140785)
numPositions: 11039874
game: (133000/140785)
numPositions: 11048192
[2019/06/22 01:30:20]
game: (133100/140785)
numPositions: 11055917
game: (133200/140785)
numPositions: 11064080
game: (133300/140785)
numPositions: 11071053
game: (133400/140785)
numPositions: 11078514
game: (133500/140785)
numPositions: 11086288
game: (133600/140785)
numPositions: 11094267
game: (133700/140785)
numPositions: 11102103
game: (133800/140785)
numPositions: 11109292
game: (133900/140785)
numPositions: 11117518
game: (134000/140785)
numPositions: 11125320
game: (134100/140785)
numPositions: 11132820
game: (134200/140785)
numPositions: 11140663
game: (134300/140785)
numPositions: 11147798
game: (134400/140785)
numPositions: 11155357
game: (134500/140785)
numPositions: 11162956
game: (134600/140785)
numPositions: 11170421
game: (134700/140785)
numPositions: 11178605
game: (134800/140785)
numPositions: 11186582
game: (134900/140785)
numPositions: 11195044
game: (135000/140785)
numPositions: 11202191
[2019/06/22 01:30:21]
game: (135100/140785)
numPositions: 11209952
game: (135200/140785)
numPositions: 11218352
game: (135300/140785)
numPositions: 11226857
game: (135400/140785)
numPositions: 11235852
game: (135500/140785)
numPositions: 11244868
game: (135600/140785)
numPositions: 11251741
game: (135700/140785)
numPositions: 11258896
game: (135800/140785)
numPositions: 11266187
game: (135900/140785)
numPositions: 11274067
game: (136000/140785)
numPositions: 11282152
game: (136100/140785)
numPositions: 11290422
game: (136200/140785)
numPositions: 11299340
game: (136300/140785)
numPositions: 11307653
game: (136400/140785)
numPositions: 11316204
game: (136500/140785)
numPositions: 11324246
game: (136600/140785)
numPositions: 11331663
game: (136700/140785)
numPositions: 11338498
game: (136800/140785)
numPositions: 11346914
game: (136900/140785)
numPositions: 11354803
[2019/06/22 01:30:22]
game: (137000/140785)
numPositions: 11362795
game: (137100/140785)
numPositions: 11370946
game: (137200/140785)
numPositions: 11379465
game: (137300/140785)
numPositions: 11387273
game: (137400/140785)
numPositions: 11394281
game: (137500/140785)
numPositions: 11402220
game: (137600/140785)
numPositions: 11409749
game: (137700/140785)
numPositions: 11417923
game: (137800/140785)
numPositions: 11425656
game: (137900/140785)
numPositions: 11433115
game: (138000/140785)
numPositions: 11440980
game: (138100/140785)
numPositions: 11449059
game: (138200/140785)
numPositions: 11457085
game: (138300/140785)
numPositions: 11464959
game: (138400/140785)
numPositions: 11473194
game: (138500/140785)
numPositions: 11480896
game: (138600/140785)
numPositions: 11488505
game: (138700/140785)
numPositions: 11496503
game: (138800/140785)
numPositions: 11504405
[2019/06/22 01:30:23]
game: (138900/140785)
numPositions: 11513057
game: (139000/140785)
numPositions: 11520869
game: (139100/140785)
numPositions: 11529231
game: (139200/140785)
numPositions: 11537331
game: (139300/140785)
numPositions: 11544933
game: (139400/140785)
numPositions: 11553569
game: (139500/140785)
numPositions: 11562367
game: (139600/140785)
numPositions: 11570342
game: (139700/140785)
numPositions: 11577970
game: (139800/140785)
numPositions: 11586237
game: (139900/140785)
numPositions: 11594561
game: (140000/140785)
numPositions: 11602462
game: (140100/140785)
numPositions: 11610597
game: (140200/140785)
numPositions: 11618716
game: (140300/140785)
numPositions: 11626713
game: (140400/140785)
numPositions: 11635135
game: (140500/140785)
numPositions: 11643741
game: (140600/140785)
numPositions: 11653041
game: (140700/140785)
numPositions: 11662244
[2019/06/22 01:30:24]
build compactedPositionInfoVec (0/140785)
build compactedPositionInfoVec (1000/140785)
build compactedPositionInfoVec (2000/140785)
build compactedPositionInfoVec (3000/140785)
build compactedPositionInfoVec (4000/140785)
build compactedPositionInfoVec (5000/140785)
build compactedPositionInfoVec (6000/140785)
build compactedPositionInfoVec (7000/140785)
build compactedPositionInfoVec (8000/140785)
build compactedPositionInfoVec (9000/140785)
build compactedPositionInfoVec (10000/140785)
build compactedPositionInfoVec (11000/140785)
build compactedPositionInfoVec (12000/140785)
build compactedPositionInfoVec (13000/140785)
build compactedPositionInfoVec (14000/140785)
build compactedPositionInfoVec (15000/140785)
build compactedPositionInfoVec (16000/140785)
build compactedPositionInfoVec (17000/140785)
build compactedPositionInfoVec (18000/140785)
build compactedPositionInfoVec (19000/140785)
build compactedPositionInfoVec (20000/140785)
build compactedPositionInfoVec (21000/140785)
build compactedPositionInfoVec (22000/140785)
build compactedPositionInfoVec (23000/140785)
build compactedPositionInfoVec (24000/140785)
build compactedPositionInfoVec (25000/140785)
build compactedPositionInfoVec (26000/140785)
build compactedPositionInfoVec (27000/140785)
build compactedPositionInfoVec (28000/140785)
build compactedPositionInfoVec (29000/140785)
build compactedPositionInfoVec (30000/140785)
build compactedPositionInfoVec (31000/140785)
build compactedPositionInfoVec (32000/140785)
build compactedPositionInfoVec (33000/140785)
build compactedPositionInfoVec (34000/140785)
build compactedPositionInfoVec (35000/140785)
build compactedPositionInfoVec (36000/140785)
build compactedPositionInfoVec (37000/140785)
build compactedPositionInfoVec (38000/140785)
build compactedPositionInfoVec (39000/140785)
build compactedPositionInfoVec (40000/140785)
build compactedPositionInfoVec (41000/140785)
build compactedPositionInfoVec (42000/140785)
build compactedPositionInfoVec (43000/140785)
build compactedPositionInfoVec (44000/140785)
build compactedPositionInfoVec (45000/140785)
build compactedPositionInfoVec (46000/140785)
build compactedPositionInfoVec (47000/140785)
build compactedPositionInfoVec (48000/140785)
build compactedPositionInfoVec (49000/140785)
build compactedPositionInfoVec (50000/140785)
build compactedPositionInfoVec (51000/140785)
build compactedPositionInfoVec (52000/140785)
build compactedPositionInfoVec (53000/140785)
build compactedPositionInfoVec (54000/140785)
build compactedPositionInfoVec (55000/140785)
build compactedPositionInfoVec (56000/140785)
build compactedPositionInfoVec (57000/140785)
build compactedPositionInfoVec (58000/140785)
build compactedPositionInfoVec (59000/140785)
build compactedPositionInfoVec (60000/140785)
build compactedPositionInfoVec (61000/140785)
build compactedPositionInfoVec (62000/140785)
build compactedPositionInfoVec (63000/140785)
build compactedPositionInfoVec (64000/140785)
build compactedPositionInfoVec (65000/140785)
build compactedPositionInfoVec (66000/140785)
build compactedPositionInfoVec (67000/140785)
build compactedPositionInfoVec (68000/140785)
build compactedPositionInfoVec (69000/140785)
build compactedPositionInfoVec (70000/140785)
build compactedPositionInfoVec (71000/140785)
build compactedPositionInfoVec (72000/140785)
build compactedPositionInfoVec (73000/140785)
build compactedPositionInfoVec (74000/140785)
build compactedPositionInfoVec (75000/140785)
build compactedPositionInfoVec (76000/140785)
build compactedPositionInfoVec (77000/140785)
build compactedPositionInfoVec (78000/140785)
build compactedPositionInfoVec (79000/140785)
build compactedPositionInfoVec (80000/140785)
build compactedPositionInfoVec (81000/140785)
build compactedPositionInfoVec (82000/140785)
build compactedPositionInfoVec (83000/140785)
build compactedPositionInfoVec (84000/140785)
build compactedPositionInfoVec (85000/140785)
build compactedPositionInfoVec (86000/140785)
build compactedPositionInfoVec (87000/140785)
build compactedPositionInfoVec (88000/140785)
build compactedPositionInfoVec (89000/140785)
build compactedPositionInfoVec (90000/140785)
build compactedPositionInfoVec (91000/140785)
build compactedPositionInfoVec (92000/140785)
build compactedPositionInfoVec (93000/140785)
build compactedPositionInfoVec (94000/140785)
build compactedPositionInfoVec (95000/140785)
build compactedPositionInfoVec (96000/140785)
build compactedPositionInfoVec (97000/140785)
build compactedPositionInfoVec (98000/140785)
build compactedPositionInfoVec (99000/140785)
build compactedPositionInfoVec (100000/140785)
build compactedPositionInfoVec (101000/140785)
build compactedPositionInfoVec (102000/140785)
build compactedPositionInfoVec (103000/140785)
build compactedPositionInfoVec (104000/140785)
build compactedPositionInfoVec (105000/140785)
build compactedPositionInfoVec (106000/140785)
build compactedPositionInfoVec (107000/140785)
build compactedPositionInfoVec (108000/140785)
build compactedPositionInfoVec (109000/140785)
build compactedPositionInfoVec (110000/140785)
build compactedPositionInfoVec (111000/140785)
build compactedPositionInfoVec (112000/140785)
build compactedPositionInfoVec (113000/140785)
build compactedPositionInfoVec (114000/140785)
build compactedPositionInfoVec (115000/140785)
build compactedPositionInfoVec (116000/140785)
build compactedPositionInfoVec (117000/140785)
build compactedPositionInfoVec (118000/140785)
build compactedPositionInfoVec (119000/140785)
build compactedPositionInfoVec (120000/140785)
build compactedPositionInfoVec (121000/140785)
build compactedPositionInfoVec (122000/140785)
build compactedPositionInfoVec (123000/140785)
build compactedPositionInfoVec (124000/140785)
build compactedPositionInfoVec (125000/140785)
build compactedPositionInfoVec (126000/140785)
build compactedPositionInfoVec (127000/140785)
build compactedPositionInfoVec (128000/140785)
build compactedPositionInfoVec (129000/140785)
build compactedPositionInfoVec (130000/140785)
build compactedPositionInfoVec (131000/140785)
build compactedPositionInfoVec (132000/140785)
build compactedPositionInfoVec (133000/140785)
build compactedPositionInfoVec (134000/140785)
build compactedPositionInfoVec (135000/140785)
build compactedPositionInfoVec (136000/140785)
build compactedPositionInfoVec (137000/140785)
build compactedPositionInfoVec (138000/140785)
build compactedPositionInfoVec (139000/140785)
[2019/06/22 01:30:25]
build compactedPositionInfoVec (140000/140785)
[2019/06/22 01:30:28]
# positions: 11669978. # to keep: 8756281, # to erase: 2913697
compactedPositionInfoVec sz: 8756281
build compactedPositionMap (0/140785)
build compactedPositionMap (1000/140785)
[2019/06/22 01:30:29]
build compactedPositionMap (2000/140785)
build compactedPositionMap (3000/140785)
build compactedPositionMap (4000/140785)
build compactedPositionMap (5000/140785)
build compactedPositionMap (6000/140785)
build compactedPositionMap (7000/140785)
build compactedPositionMap (8000/140785)
build compactedPositionMap (9000/140785)
build compactedPositionMap (10000/140785)
build compactedPositionMap (11000/140785)
build compactedPositionMap (12000/140785)
build compactedPositionMap (13000/140785)
build compactedPositionMap (14000/140785)
[2019/06/22 01:30:30]
build compactedPositionMap (15000/140785)
build compactedPositionMap (16000/140785)
build compactedPositionMap (17000/140785)
build compactedPositionMap (18000/140785)
build compactedPositionMap (19000/140785)
build compactedPositionMap (20000/140785)
build compactedPositionMap (21000/140785)
build compactedPositionMap (22000/140785)
build compactedPositionMap (23000/140785)
build compactedPositionMap (24000/140785)
build compactedPositionMap (25000/140785)
build compactedPositionMap (26000/140785)
build compactedPositionMap (27000/140785)
[2019/06/22 01:30:31]
build compactedPositionMap (28000/140785)
build compactedPositionMap (29000/140785)
build compactedPositionMap (30000/140785)
build compactedPositionMap (31000/140785)
build compactedPositionMap (32000/140785)
build compactedPositionMap (33000/140785)
build compactedPositionMap (34000/140785)
build compactedPositionMap (35000/140785)
build compactedPositionMap (36000/140785)
build compactedPositionMap (37000/140785)
build compactedPositionMap (38000/140785)
build compactedPositionMap (39000/140785)
build compactedPositionMap (40000/140785)
[2019/06/22 01:30:32]
build compactedPositionMap (41000/140785)
build compactedPositionMap (42000/140785)
build compactedPositionMap (43000/140785)
build compactedPositionMap (44000/140785)
build compactedPositionMap (45000/140785)
build compactedPositionMap (46000/140785)
build compactedPositionMap (47000/140785)
build compactedPositionMap (48000/140785)
build compactedPositionMap (49000/140785)
build compactedPositionMap (50000/140785)
build compactedPositionMap (51000/140785)
build compactedPositionMap (52000/140785)
build compactedPositionMap (53000/140785)
[2019/06/22 01:30:33]
build compactedPositionMap (54000/140785)
build compactedPositionMap (55000/140785)
build compactedPositionMap (56000/140785)
build compactedPositionMap (57000/140785)
build compactedPositionMap (58000/140785)
build compactedPositionMap (59000/140785)
build compactedPositionMap (60000/140785)
build compactedPositionMap (61000/140785)
build compactedPositionMap (62000/140785)
build compactedPositionMap (63000/140785)
build compactedPositionMap (64000/140785)
build compactedPositionMap (65000/140785)
[2019/06/22 01:30:34]
build compactedPositionMap (66000/140785)
build compactedPositionMap (67000/140785)
build compactedPositionMap (68000/140785)
build compactedPositionMap (69000/140785)
build compactedPositionMap (70000/140785)
build compactedPositionMap (71000/140785)
build compactedPositionMap (72000/140785)
build compactedPositionMap (73000/140785)
build compactedPositionMap (74000/140785)
build compactedPositionMap (75000/140785)
build compactedPositionMap (76000/140785)
build compactedPositionMap (77000/140785)
build compactedPositionMap (78000/140785)
build compactedPositionMap (79000/140785)
[2019/06/22 01:30:35]
build compactedPositionMap (80000/140785)
build compactedPositionMap (81000/140785)
build compactedPositionMap (82000/140785)
build compactedPositionMap (83000/140785)
build compactedPositionMap (84000/140785)
build compactedPositionMap (85000/140785)
build compactedPositionMap (86000/140785)
build compactedPositionMap (87000/140785)
build compactedPositionMap (88000/140785)
build compactedPositionMap (89000/140785)
build compactedPositionMap (90000/140785)
build compactedPositionMap (91000/140785)
build compactedPositionMap (92000/140785)
build compactedPositionMap (93000/140785)
[2019/06/22 01:30:36]
build compactedPositionMap (94000/140785)
build compactedPositionMap (95000/140785)
build compactedPositionMap (96000/140785)
build compactedPositionMap (97000/140785)
build compactedPositionMap (98000/140785)
build compactedPositionMap (99000/140785)
build compactedPositionMap (100000/140785)
build compactedPositionMap (101000/140785)
build compactedPositionMap (102000/140785)
build compactedPositionMap (103000/140785)
build compactedPositionMap (104000/140785)
build compactedPositionMap (105000/140785)
build compactedPositionMap (106000/140785)
build compactedPositionMap (107000/140785)
build compactedPositionMap (108000/140785)
[2019/06/22 01:30:37]
build compactedPositionMap (109000/140785)
build compactedPositionMap (110000/140785)
build compactedPositionMap (111000/140785)
build compactedPositionMap (112000/140785)
build compactedPositionMap (113000/140785)
build compactedPositionMap (114000/140785)
build compactedPositionMap (115000/140785)
build compactedPositionMap (116000/140785)
build compactedPositionMap (117000/140785)
build compactedPositionMap (118000/140785)
build compactedPositionMap (119000/140785)
build compactedPositionMap (120000/140785)
build compactedPositionMap (121000/140785)
build compactedPositionMap (122000/140785)
[2019/06/22 01:30:38]
build compactedPositionMap (123000/140785)
build compactedPositionMap (124000/140785)
build compactedPositionMap (125000/140785)
build compactedPositionMap (126000/140785)
build compactedPositionMap (127000/140785)
build compactedPositionMap (128000/140785)
build compactedPositionMap (129000/140785)
build compactedPositionMap (130000/140785)
build compactedPositionMap (131000/140785)
build compactedPositionMap (132000/140785)
build compactedPositionMap (133000/140785)
build compactedPositionMap (134000/140785)
[2019/06/22 01:30:39]
build compactedPositionMap (135000/140785)
build compactedPositionMap (136000/140785)
build compactedPositionMap (137000/140785)
build compactedPositionMap (138000/140785)
build compactedPositionMap (139000/140785)
build compactedPositionMap (140000/140785)
=====================================================================
+21647/=26916/-16006/*3 -- (+33.5238/=41.6837/-24.7878/*0.00464598)
=====================================================================
=====================================================================
+0/=1/-0/*0 -- (+0/=100/-0/*0)
=====================================================================
done
FunctionTimerBoard::log
time(name: GameParser::parsePGN parser, numMS: 313, numCalls: 2773368, timePerCall: 0.000113
time(name: GameParser::parseLine_InGameMoves, numMS: 85, numCalls: 950596, timePerCall: 0.000089
time(name: GameParser::generateCompactedPositions - pos.getNextPosition, numMS: 1, numCalls: 11669978, timePerCall: 0.000000
time(name: GameParser::generateCompactedPositions - pos.toCompactedPos, numMS: 115, numCalls: 11669978, timePerCall: 0.000010
time(name: GameParser::fillCompactedPositionInfoVec - build compactedPositionInfoVec, numMS: 0, numCalls: 140785, timePerCall: 0.000000
time(name: GameParser::fillCompactedPositionInfoVec - sort, numMS: 2959, numCalls: 1, timePerCall: 2959.000000
time(name: GameParser::fillCompactedPositionInfoVec - erase, numMS: 914, numCalls: 1, timePerCall: 914.000000
time(name: GameParser::fillCompactedPositionInfoVec - build compactedPositionMap, numMS: 42, numCalls: 140785, timePerCall: 0.000298
#FunctionTimerBoard::log

