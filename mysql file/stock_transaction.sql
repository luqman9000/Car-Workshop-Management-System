-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 17, 2021 at 02:26 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `stock_transaction`
--

-- --------------------------------------------------------

--
-- Table structure for table `service`
--

CREATE TABLE `service` (
  `ID` int(11) NOT NULL,
  `Staff` varchar(255) NOT NULL,
  `Service` varchar(255) NOT NULL,
  `Price` float NOT NULL,
  `date` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `service`
--

INSERT INTO `service` (`ID`, `Staff`, `Service`, `Price`, `date`) VALUES
(215, 'Amirul', 'Change engine oil', 10, '2021-01-13 13:50:40'),
(216, 'Amirul', 'Engine oil', 10, '2021-01-13 13:52:07'),
(217, 'Amirul', 'Pump tyre', 0, '2021-01-13 14:17:21'),
(218, 'Amirul', 'Change engine oil', 10, '2021-01-13 14:18:46'),
(219, 'Amirul', 'Pump tyre', 10, '2021-01-13 14:27:57'),
(231, 'Amirul', 'Change engine oil', 10, '2021-01-13 16:04:13'),
(232, 'Amirul', 'Change tyre', 10, '2021-01-13 16:52:56'),
(233, 'Amir', 'Change engine oil', 10, '2021-01-13 16:53:18'),
(234, 'Amirul', 'Change engine oil', 10, '2021-01-14 20:33:26'),
(235, 'Amirul', 'Change tyre', 5, '2021-01-14 20:33:56'),
(236, 'Amirul', 'Change the engine oil', 10, '2021-01-15 01:21:20'),
(237, 'Amirul', 'Change tyre', 5, '2021-01-15 01:21:48');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `staffid` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `staffpassword` varchar(255) NOT NULL,
  `FirstName` varchar(255) NOT NULL,
  `LastName` varchar(255) NOT NULL,
  `phonenumber` varchar(11) NOT NULL,
  `job` varchar(255) NOT NULL,
  `Role` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`staffid`, `username`, `staffpassword`, `FirstName`, `LastName`, `phonenumber`, `job`, `Role`) VALUES
(5, 's_amirul', 'staff12', 'Amirul', 'Syafiq', '0123456789', 'Mechanic', 'Staff'),
(7, 'a_amir', 'amir12', 'Amir', 'Syafiq', '0129812745', 'HR', 'Admin'),
(8, 's_ainu', 'tmnet123', 'Ainu', 'Amir', '0193891859', 'Cashier', 'Staff'),
(9, 's_zais', 'zais12', 'Zaid', 'Aqil', '0194869301', 'Mechanic', 'Staff'),
(12, 's_adam', 'adam12', 'Adam', 'Afeeq', '0194895938', 'Mechanic', 'Staff');

-- --------------------------------------------------------

--
-- Table structure for table `stock`
--

CREATE TABLE `stock` (
  `ID` int(11) NOT NULL,
  `description` varchar(255) NOT NULL,
  `Price` float NOT NULL,
  `Amount` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `stock`
--

INSERT INTO `stock` (`ID`, `description`, `Price`, `Amount`) VALUES
(10, 'Engine 4AGE', 5000, 3);

-- --------------------------------------------------------

--
-- Table structure for table `transaction`
--

CREATE TABLE `transaction` (
  `ID` int(11) NOT NULL,
  `spare_part` varchar(255) NOT NULL,
  `Quantity` int(11) NOT NULL,
  `Price` decimal(65,0) NOT NULL,
  `Staff` varchar(255) NOT NULL,
  `Time` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction`
--

INSERT INTO `transaction` (`ID`, `spare_part`, `Quantity`, `Price`, `Staff`, `Time`) VALUES
(25, 'Engine 4AGE', 2, '5000', '', '2021-01-04 11:48:22'),
(26, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:18:15'),
(27, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:21:20'),
(28, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:21:35'),
(29, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:21:44'),
(30, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:39:50'),
(31, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:40:06'),
(32, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:48:55'),
(33, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:49:08'),
(34, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:53:42'),
(35, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:53:51'),
(36, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:54:18'),
(37, 'Engine 4AGE', 1, '5000', '', '2021-01-14 01:55:25'),
(38, 'Engine 4AGE', 1, '5000', 'Amir', '2021-01-14 01:55:35'),
(39, 'Engine 4AGE', 1, '5000', '', '2021-01-15 03:19:58'),
(44, 'Engine 4AGE', 1, '5000', 'Amirul', '2021-01-15 03:35:54'),
(45, 'Engine 4AGE', 1, '5000', 'Amirul', '2021-01-15 04:11:58'),
(46, 'Engine 4AGE', 2, '5000', 'Amirul', '2021-01-15 04:12:35'),
(47, 'Engine 4AGE', 1, '5000', 'Amirul', '2021-01-15 04:12:51'),
(48, 'Engine 4AGE', 1, '5000', 'Zaid', '2021-01-15 08:41:10'),
(49, 'Engine 4AGE', 1, '5000', 'Zaid', '2021-01-15 08:41:26'),
(50, 'Engine 4AGE', 1, '5000', 'Adam', '2021-01-15 09:23:09'),
(51, 'Engine 4AGE', 2, '5000', 'Adam', '2021-01-15 09:23:27');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `service`
--
ALTER TABLE `service`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`staffid`),
  ADD UNIQUE KEY `username` (`username`,`staffpassword`,`FirstName`,`LastName`,`phonenumber`) USING HASH;

--
-- Indexes for table `stock`
--
ALTER TABLE `stock`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `transaction`
--
ALTER TABLE `transaction`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `service`
--
ALTER TABLE `service`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=238;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `staffid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `stock`
--
ALTER TABLE `stock`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `transaction`
--
ALTER TABLE `transaction`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=52;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
