-- phpMyAdmin SQL Dump
-- version 4.7.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:8889
-- Erstellungszeit: 04. Feb 2018 um 23:33
-- Server-Version: 5.6.38
-- PHP-Version: 7.1.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Datenbank: `DPSG-Windrose-Test`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `users`
--

CREATE TABLE `users` (
`Username` varchar(50) COLLATE utf8_bin NOT NULL,
`Password` varchar(255) COLLATE utf8_bin NOT NULL,
`ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Daten für Tabelle `users`
--

INSERT INTO `users` (`Username`, `Password`, `ID`) VALUES
('Cedric', '$2y$10$ZzDzSwYQgqXzCR7D/jZg4OWIQ/xIBbPTNs5m5v4TZHLuh6pncMxZG', 9),
('Norman', '$2y$10$MrCYaeL8/x/mXnrvAj7Jb.oPry3nAeCipA4ySaDBBrm/gZtpsj39.', 10);

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `users`
--
ALTER TABLE `users`
ADD UNIQUE KEY `ID` (`ID`);

--
-- AUTO_INCREMENT für exportierte Tabellen
--

--
-- AUTO_INCREMENT für Tabelle `users`
--
ALTER TABLE `users`
MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
