
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 05/25/2016 22:53:21
-- Generated from EDMX file: D:\编程\数据库\homework\CMSystem\Meeting\MeetingModel\Model1.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [CMSystem];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK__acompany___re_id__2C3393D0]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[acompany_retinue] DROP CONSTRAINT [FK__acompany___re_id__2C3393D0];
GO
IF OBJECT_ID(N'[dbo].[FK__acompany_retinue__2B3F6F97]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[acompany_retinue] DROP CONSTRAINT [FK__acompany_retinue__2B3F6F97];
GO
IF OBJECT_ID(N'[dbo].[FK__Admins__dept_id__1CF15040]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Admins] DROP CONSTRAINT [FK__Admins__dept_id__1CF15040];
GO
IF OBJECT_ID(N'[dbo].[FK__Admins__id__1BFD2C07]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Admins] DROP CONSTRAINT [FK__Admins__id__1BFD2C07];
GO
IF OBJECT_ID(N'[dbo].[FK__Meetings__h_name__24927208]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Meetings] DROP CONSTRAINT [FK__Meetings__h_name__24927208];
GO
IF OBJECT_ID(N'[dbo].[FK__Ordusers__id__1FCDBCEB]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Ordusers] DROP CONSTRAINT [FK__Ordusers__id__1FCDBCEB];
GO
IF OBJECT_ID(N'[dbo].[FK__P_attend___users__276EDEB3]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[P_attend_m] DROP CONSTRAINT [FK__P_attend___users__276EDEB3];
GO
IF OBJECT_ID(N'[dbo].[FK__P_attend_m__m_id__286302EC]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[P_attend_m] DROP CONSTRAINT [FK__P_attend_m__m_id__286302EC];
GO
IF OBJECT_ID(N'[dbo].[FK__Supadmin__id__173876EA]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Supadmin] DROP CONSTRAINT [FK__Supadmin__id__173876EA];
GO
IF OBJECT_ID(N'[dbo].[FK__Users__id__145C0A3F]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Users] DROP CONSTRAINT [FK__Users__id__145C0A3F];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[acompany_retinue]', 'U') IS NOT NULL
    DROP TABLE [dbo].[acompany_retinue];
GO
IF OBJECT_ID(N'[dbo].[Admins]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Admins];
GO
IF OBJECT_ID(N'[dbo].[Departments]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Departments];
GO
IF OBJECT_ID(N'[dbo].[Hotels]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Hotels];
GO
IF OBJECT_ID(N'[dbo].[Meetings]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Meetings];
GO
IF OBJECT_ID(N'[dbo].[Ordusers]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Ordusers];
GO
IF OBJECT_ID(N'[dbo].[P_attend_m]', 'U') IS NOT NULL
    DROP TABLE [dbo].[P_attend_m];
GO
IF OBJECT_ID(N'[dbo].[Persons]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Persons];
GO
IF OBJECT_ID(N'[dbo].[Supadmin]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Supadmin];
GO
IF OBJECT_ID(N'[dbo].[Users]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Users];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'acompany_retinue'
CREATE TABLE [dbo].[acompany_retinue] (
    [users_id] varchar(18)  NOT NULL,
    [m_id] varchar(8)  NOT NULL,
    [re_id] varchar(18)  NOT NULL,
    [roomnumber] varchar(5)  NOT NULL
);
GO

-- Creating table 'Admins'
CREATE TABLE [dbo].[Admins] (
    [id] varchar(18)  NOT NULL,
    [dept_id] varchar(7)  NULL
);
GO

-- Creating table 'Departments'
CREATE TABLE [dbo].[Departments] (
    [dept_id] varchar(7)  NOT NULL,
    [dept_name] varchar(20)  NULL
);
GO

-- Creating table 'Hotels'
CREATE TABLE [dbo].[Hotels] (
    [h_name] varchar(15)  NOT NULL,
    [h_address] varchar(30)  NOT NULL,
    [phone_number] varchar(12)  NULL
);
GO

-- Creating table 'Meetings'
CREATE TABLE [dbo].[Meetings] (
    [m_id] varchar(8)  NOT NULL,
    [m_name] varchar(20)  NOT NULL,
    [pre_num] int  NULL,
    [max_num] int  NULL,
    [theme] varchar(30)  NULL,
    [begin_date] datetime  NOT NULL,
    [begin_time] time  NOT NULL,
    [end_date] datetime  NULL,
    [end_time] time  NULL,
    [m_city] varchar(15)  NOT NULL,
    [m_address] varchar(30)  NOT NULL,
    [h_name] varchar(15)  NULL
);
GO

-- Creating table 'Ordusers'
CREATE TABLE [dbo].[Ordusers] (
    [id] varchar(18)  NOT NULL
);
GO

-- Creating table 'P_attend_m'
CREATE TABLE [dbo].[P_attend_m] (
    [users_id] varchar(18)  NOT NULL,
    [m_id] varchar(8)  NOT NULL,
    [arrive_date] datetime  NULL,
    [arrive_way] varchar(6)  NULL,
    [leave_date] datetime  NULL,
    [leave_way] varchar(6)  NULL,
    [room_number] varchar(5)  NULL
);
GO

-- Creating table 'Persons'
CREATE TABLE [dbo].[Persons] (
    [id] varchar(18)  NOT NULL,
    [name] varchar(20)  NULL,
    [gender] char(1)  NULL
);
GO

-- Creating table 'Supadmin'
CREATE TABLE [dbo].[Supadmin] (
    [id] varchar(18)  NOT NULL
);
GO

-- Creating table 'Users'
CREATE TABLE [dbo].[Users] (
    [id] varchar(18)  NOT NULL,
    [psw] varchar(25)  NOT NULL,
    [e_mail] varchar(25)  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [users_id], [m_id], [re_id] in table 'acompany_retinue'
ALTER TABLE [dbo].[acompany_retinue]
ADD CONSTRAINT [PK_acompany_retinue]
    PRIMARY KEY CLUSTERED ([users_id], [m_id], [re_id] ASC);
GO

-- Creating primary key on [id] in table 'Admins'
ALTER TABLE [dbo].[Admins]
ADD CONSTRAINT [PK_Admins]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [dept_id] in table 'Departments'
ALTER TABLE [dbo].[Departments]
ADD CONSTRAINT [PK_Departments]
    PRIMARY KEY CLUSTERED ([dept_id] ASC);
GO

-- Creating primary key on [h_name] in table 'Hotels'
ALTER TABLE [dbo].[Hotels]
ADD CONSTRAINT [PK_Hotels]
    PRIMARY KEY CLUSTERED ([h_name] ASC);
GO

-- Creating primary key on [m_id] in table 'Meetings'
ALTER TABLE [dbo].[Meetings]
ADD CONSTRAINT [PK_Meetings]
    PRIMARY KEY CLUSTERED ([m_id] ASC);
GO

-- Creating primary key on [id] in table 'Ordusers'
ALTER TABLE [dbo].[Ordusers]
ADD CONSTRAINT [PK_Ordusers]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [users_id], [m_id] in table 'P_attend_m'
ALTER TABLE [dbo].[P_attend_m]
ADD CONSTRAINT [PK_P_attend_m]
    PRIMARY KEY CLUSTERED ([users_id], [m_id] ASC);
GO

-- Creating primary key on [id] in table 'Persons'
ALTER TABLE [dbo].[Persons]
ADD CONSTRAINT [PK_Persons]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [id] in table 'Supadmin'
ALTER TABLE [dbo].[Supadmin]
ADD CONSTRAINT [PK_Supadmin]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [id] in table 'Users'
ALTER TABLE [dbo].[Users]
ADD CONSTRAINT [PK_Users]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [re_id] in table 'acompany_retinue'
ALTER TABLE [dbo].[acompany_retinue]
ADD CONSTRAINT [FK__acompany___re_id__2C3393D0]
    FOREIGN KEY ([re_id])
    REFERENCES [dbo].[Persons]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__acompany___re_id__2C3393D0'
CREATE INDEX [IX_FK__acompany___re_id__2C3393D0]
ON [dbo].[acompany_retinue]
    ([re_id]);
GO

-- Creating foreign key on [users_id], [m_id] in table 'acompany_retinue'
ALTER TABLE [dbo].[acompany_retinue]
ADD CONSTRAINT [FK__acompany_retinue__2B3F6F97]
    FOREIGN KEY ([users_id], [m_id])
    REFERENCES [dbo].[P_attend_m]
        ([users_id], [m_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [dept_id] in table 'Admins'
ALTER TABLE [dbo].[Admins]
ADD CONSTRAINT [FK__Admins__dept_id__1CF15040]
    FOREIGN KEY ([dept_id])
    REFERENCES [dbo].[Departments]
        ([dept_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__Admins__dept_id__1CF15040'
CREATE INDEX [IX_FK__Admins__dept_id__1CF15040]
ON [dbo].[Admins]
    ([dept_id]);
GO

-- Creating foreign key on [id] in table 'Admins'
ALTER TABLE [dbo].[Admins]
ADD CONSTRAINT [FK__Admins__id__1BFD2C07]
    FOREIGN KEY ([id])
    REFERENCES [dbo].[Users]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [h_name] in table 'Meetings'
ALTER TABLE [dbo].[Meetings]
ADD CONSTRAINT [FK__Meetings__h_name__24927208]
    FOREIGN KEY ([h_name])
    REFERENCES [dbo].[Hotels]
        ([h_name])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__Meetings__h_name__24927208'
CREATE INDEX [IX_FK__Meetings__h_name__24927208]
ON [dbo].[Meetings]
    ([h_name]);
GO

-- Creating foreign key on [m_id] in table 'P_attend_m'
ALTER TABLE [dbo].[P_attend_m]
ADD CONSTRAINT [FK__P_attend_m__m_id__286302EC]
    FOREIGN KEY ([m_id])
    REFERENCES [dbo].[Meetings]
        ([m_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;

-- Creating non-clustered index for FOREIGN KEY 'FK__P_attend_m__m_id__286302EC'
CREATE INDEX [IX_FK__P_attend_m__m_id__286302EC]
ON [dbo].[P_attend_m]
    ([m_id]);
GO

-- Creating foreign key on [id] in table 'Ordusers'
ALTER TABLE [dbo].[Ordusers]
ADD CONSTRAINT [FK__Ordusers__id__1FCDBCEB]
    FOREIGN KEY ([id])
    REFERENCES [dbo].[Users]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [users_id] in table 'P_attend_m'
ALTER TABLE [dbo].[P_attend_m]
ADD CONSTRAINT [FK__P_attend___users__276EDEB3]
    FOREIGN KEY ([users_id])
    REFERENCES [dbo].[Users]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [id] in table 'Users'
ALTER TABLE [dbo].[Users]
ADD CONSTRAINT [FK__Users__id__145C0A3F]
    FOREIGN KEY ([id])
    REFERENCES [dbo].[Persons]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [id] in table 'Supadmin'
ALTER TABLE [dbo].[Supadmin]
ADD CONSTRAINT [FK__Supadmin__id__173876EA]
    FOREIGN KEY ([id])
    REFERENCES [dbo].[Users]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------