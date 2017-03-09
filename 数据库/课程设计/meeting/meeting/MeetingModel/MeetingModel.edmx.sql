
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 06/06/2016 23:45:23
-- Generated from EDMX file: D:\编程\数据库\课程设计\meeting\meeting\MeetingModel\MeetingModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [meeting];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK__accompany__2D27B809]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[accompany] DROP CONSTRAINT [FK__accompany__2D27B809];
GO
IF OBJECT_ID(N'[dbo].[FK__accompany__h_nam__2F10007B]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[accompany] DROP CONSTRAINT [FK__accompany__h_nam__2F10007B];
GO
IF OBJECT_ID(N'[dbo].[FK__Admin__dept_id__145C0A3F]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Admin] DROP CONSTRAINT [FK__Admin__dept_id__145C0A3F];
GO
IF OBJECT_ID(N'[dbo].[FK__attend__h_name__267ABA7A]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[attend] DROP CONSTRAINT [FK__attend__h_name__267ABA7A];
GO
IF OBJECT_ID(N'[dbo].[FK__attend__m_id__25869641]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[attend] DROP CONSTRAINT [FK__attend__m_id__25869641];
GO
IF OBJECT_ID(N'[dbo].[FK__attend__particip__24927208]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[attend] DROP CONSTRAINT [FK__attend__particip__24927208];
GO
IF OBJECT_ID(N'[dbo].[FK__Meeting__dept_id__1CF15040]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Meeting] DROP CONSTRAINT [FK__Meeting__dept_id__1CF15040];
GO
IF OBJECT_ID(N'[dbo].[FK__agenda__m_id__1FCDBCEB]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[agenda] DROP CONSTRAINT [FK__agenda__m_id__1FCDBCEB];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[accompany]', 'U') IS NOT NULL
    DROP TABLE [dbo].[accompany];
GO
IF OBJECT_ID(N'[dbo].[Admin]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Admin];
GO
IF OBJECT_ID(N'[dbo].[attend]', 'U') IS NOT NULL
    DROP TABLE [dbo].[attend];
GO
IF OBJECT_ID(N'[dbo].[Department]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Department];
GO
IF OBJECT_ID(N'[dbo].[Hotel]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Hotel];
GO
IF OBJECT_ID(N'[dbo].[Meeting]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Meeting];
GO
IF OBJECT_ID(N'[dbo].[Orduser]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Orduser];
GO
IF OBJECT_ID(N'[dbo].[Supadmin]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Supadmin];
GO
IF OBJECT_ID(N'[dbo].[agenda]', 'U') IS NOT NULL
    DROP TABLE [dbo].[agenda];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'accompany'
CREATE TABLE [dbo].[accompany] (
    [participator_id] int  NOT NULL,
    [m_id] int  NOT NULL,
    [re_id] int  NOT NULL,
    [h_name] varchar(15)  NULL,
    [roomnumber] int  NOT NULL
);
GO

-- Creating table 'Admin'
CREATE TABLE [dbo].[Admin] (
    [id] int  NOT NULL,
    [psw] varchar(25)  NOT NULL,
    [dept_id] varchar(30)  NULL
);
GO

-- Creating table 'attend'
CREATE TABLE [dbo].[attend] (
    [participator_id] int  NOT NULL,
    [m_id] int  NOT NULL,
    [arrive_date] datetime  NULL,
    [arrive_way] varchar(6)  NULL,
    [leave_date] datetime  NULL,
    [leave_way] varchar(6)  NULL,
    [h_name] varchar(15)  NULL,
    [room_number] int  NULL
);
GO

-- Creating table 'Department'
CREATE TABLE [dbo].[Department] (
    [dept_id] varchar(30)  NOT NULL,
    [dept_name] varchar(20)  NULL
);
GO

-- Creating table 'Hotel'
CREATE TABLE [dbo].[Hotel] (
    [h_name] varchar(15)  NOT NULL,
    [h_street] varchar(30)  NOT NULL,
    [h_number] int  NULL,
    [phone_number] varchar(12)  NULL
);
GO

-- Creating table 'Meeting'
CREATE TABLE [dbo].[Meeting] (
    [m_id] int IDENTITY(1,1) NOT NULL,
    [m_name] varchar(20)  NOT NULL,
    [theme] varchar(30)  NULL,
    [begin_time] datetime  NOT NULL,
    [end_time] datetime  NULL,
    [m_city] varchar(15)  NOT NULL,
    [m_street] varchar(30)  NOT NULL,
    [m_number] int  NULL,
    [dept_id] varchar(30)  NULL
);
GO

-- Creating table 'Orduser'
CREATE TABLE [dbo].[Orduser] (
    [id] int  NOT NULL,
    [gender] char(1)  NULL,
    [e_mail] varchar(25)  NOT NULL
);
GO

-- Creating table 'Supadmin'
CREATE TABLE [dbo].[Supadmin] (
    [id] int  NOT NULL,
    [psw] varchar(25)  NOT NULL
);
GO

-- Creating table 'agenda'
CREATE TABLE [dbo].[agenda] (
    [m_id] int  NULL,
    [detail] varchar(300)  NULL,
    [starttime] datetime  NULL,
    [endtime] datetime  NULL,
    [agenda_number] int IDENTITY(1,1) NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [participator_id], [m_id], [re_id] in table 'accompany'
ALTER TABLE [dbo].[accompany]
ADD CONSTRAINT [PK_accompany]
    PRIMARY KEY CLUSTERED ([participator_id], [m_id], [re_id] ASC);
GO

-- Creating primary key on [id] in table 'Admin'
ALTER TABLE [dbo].[Admin]
ADD CONSTRAINT [PK_Admin]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [participator_id], [m_id] in table 'attend'
ALTER TABLE [dbo].[attend]
ADD CONSTRAINT [PK_attend]
    PRIMARY KEY CLUSTERED ([participator_id], [m_id] ASC);
GO

-- Creating primary key on [dept_id] in table 'Department'
ALTER TABLE [dbo].[Department]
ADD CONSTRAINT [PK_Department]
    PRIMARY KEY CLUSTERED ([dept_id] ASC);
GO

-- Creating primary key on [h_name] in table 'Hotel'
ALTER TABLE [dbo].[Hotel]
ADD CONSTRAINT [PK_Hotel]
    PRIMARY KEY CLUSTERED ([h_name] ASC);
GO

-- Creating primary key on [m_id] in table 'Meeting'
ALTER TABLE [dbo].[Meeting]
ADD CONSTRAINT [PK_Meeting]
    PRIMARY KEY CLUSTERED ([m_id] ASC);
GO

-- Creating primary key on [id] in table 'Orduser'
ALTER TABLE [dbo].[Orduser]
ADD CONSTRAINT [PK_Orduser]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [id] in table 'Supadmin'
ALTER TABLE [dbo].[Supadmin]
ADD CONSTRAINT [PK_Supadmin]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [agenda_number] in table 'agenda'
ALTER TABLE [dbo].[agenda]
ADD CONSTRAINT [PK_agenda]
    PRIMARY KEY CLUSTERED ([agenda_number] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [participator_id], [m_id] in table 'accompany'
ALTER TABLE [dbo].[accompany]
ADD CONSTRAINT [FK__accompany__2D27B809]
    FOREIGN KEY ([participator_id], [m_id])
    REFERENCES [dbo].[attend]
        ([participator_id], [m_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [h_name] in table 'accompany'
ALTER TABLE [dbo].[accompany]
ADD CONSTRAINT [FK__accompany__h_nam__2F10007B]
    FOREIGN KEY ([h_name])
    REFERENCES [dbo].[Hotel]
        ([h_name])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__accompany__h_nam__2F10007B'
CREATE INDEX [IX_FK__accompany__h_nam__2F10007B]
ON [dbo].[accompany]
    ([h_name]);
GO

-- Creating foreign key on [dept_id] in table 'Admin'
ALTER TABLE [dbo].[Admin]
ADD CONSTRAINT [FK__Admin__dept_id__145C0A3F]
    FOREIGN KEY ([dept_id])
    REFERENCES [dbo].[Department]
        ([dept_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__Admin__dept_id__145C0A3F'
CREATE INDEX [IX_FK__Admin__dept_id__145C0A3F]
ON [dbo].[Admin]
    ([dept_id]);
GO

-- Creating foreign key on [h_name] in table 'attend'
ALTER TABLE [dbo].[attend]
ADD CONSTRAINT [FK__attend__h_name__267ABA7A]
    FOREIGN KEY ([h_name])
    REFERENCES [dbo].[Hotel]
        ([h_name])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__attend__h_name__267ABA7A'
CREATE INDEX [IX_FK__attend__h_name__267ABA7A]
ON [dbo].[attend]
    ([h_name]);
GO

-- Creating foreign key on [m_id] in table 'attend'
ALTER TABLE [dbo].[attend]
ADD CONSTRAINT [FK__attend__m_id__25869641]
    FOREIGN KEY ([m_id])
    REFERENCES [dbo].[Meeting]
        ([m_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__attend__m_id__25869641'
CREATE INDEX [IX_FK__attend__m_id__25869641]
ON [dbo].[attend]
    ([m_id]);
GO

-- Creating foreign key on [participator_id] in table 'attend'
ALTER TABLE [dbo].[attend]
ADD CONSTRAINT [FK__attend__particip__24927208]
    FOREIGN KEY ([participator_id])
    REFERENCES [dbo].[Orduser]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [dept_id] in table 'Meeting'
ALTER TABLE [dbo].[Meeting]
ADD CONSTRAINT [FK__Meeting__dept_id__1CF15040]
    FOREIGN KEY ([dept_id])
    REFERENCES [dbo].[Department]
        ([dept_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__Meeting__dept_id__1CF15040'
CREATE INDEX [IX_FK__Meeting__dept_id__1CF15040]
ON [dbo].[Meeting]
    ([dept_id]);
GO

-- Creating foreign key on [m_id] in table 'agenda'
ALTER TABLE [dbo].[agenda]
ADD CONSTRAINT [FK__agenda__m_id__1FCDBCEB]
    FOREIGN KEY ([m_id])
    REFERENCES [dbo].[Meeting]
        ([m_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__agenda__m_id__1FCDBCEB'
CREATE INDEX [IX_FK__agenda__m_id__1FCDBCEB]
ON [dbo].[agenda]
    ([m_id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------